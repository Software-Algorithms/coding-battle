/*
 * Union Find
 *
 */
class UnionFind { 
public:
    UnionFind(int n) {
        // initialize your data structure here.
        father.resize(n);
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    void connect(int a, int b) {
        // Write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father[root_a] = root_b;
            count--;
        }
    }
        
    int query() {
        // Write your code here
        return count;
    }
    
    void set_count(int total) {
        count = total;
    }
    
private:
    vector<int> father;
    int count;

    int find(int x) {
        if (father[x] == x) {
            return x;
        }
        return father[x] = find(father[x]);
    }
};

class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if(grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        
        UnionFind union_find(m * n);
        
        int total = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    total++;
                }
            }
        }
    
        union_find.set_count(total);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
            if (grid[i][j]) {
                if (i > 0 && grid[i-1][j]) union_find.connect(i*n+j, (i-1)*n+j); // up
                if (i <  m-1 && grid[i + 1][j]) union_find.connect(i*n+j, (i+1)*n+j); // down
                if (j > 0 && grid[i][j-1]) union_find.connect(i*n+j, i*n+j-1); // left
                if (j < n-1 && grid[i][j+1]) union_find.connect(i*n+j, i*n+j+1); // right
            }
        return union_find.query();
    }
};

// Conclusion:
// Quick deployment of Union Find class is a must.




 /*
 * DFS
 *
 */

// version 1: using an array "visited" to avoid repeating
class Solution {
public:
    int numIslands(vector<vector<char> > &grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    numIslandsDFS(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
    void numIslandsDFS(vector<vector<char> > &grid, vector<vector<bool> > &visited, int x, int y) {
        if (x < 0 || x >= grid.size()) return;
        if (y < 0 || y >= grid[0].size()) return;
        if (grid[x][y] != '1' || visited[x][y]) return;
        visited[x][y] = true;
        numIslandsDFS(grid, visited, x - 1, y);
        numIslandsDFS(grid, visited, x + 1, y);
        numIslandsDFS(grid, visited, x, y - 1);
        numIslandsDFS(grid, visited, x, y + 1);
    }
};


// version 2: "Drown island", using itself as "visited" array.
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    drownIslands(grid, i, j);
                    count++;
                }
            }
        }
        return count;        
    }

    void drownIslands(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] == '0') return;
        grid[x][y] = '0';
        drownIslands(grid, x-1, y);
        drownIslands(grid, x+1, y);
        drownIslands(grid, x, y-1);
        drownIslands(grid, x, y+1);
        return;
    }
};

// Conclusion:
// Very typical dfs problem.




/*
 *
 *
 */
struct Cell {
    int x, y;
    Cell(int _x, int _y) : x(_x), y(_y) {}
};

class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if(grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        int islands = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    markByBFS(grid, i, j);
                    islands++;
                }
            }
        }
        
        return islands;
    }
    
private:
    void markByBFS(vector<vector<bool>> &grid, int x, int y) {
        // magic numbers!
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        queue<Cell> q;
        q.push(Cell(x, y));
        grid[x][y] = false;
        
        while (!q.empty()) {
            Cell t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                Cell adj(t.x + dirs[i][0], t.y + dirs[i][1]);
                if (!inBound(adj, grid) || !grid[adj.x][adj.y]) continue;
                grid[adj.x][adj.y] = false;
                q.push(adj);
            }
        }
    }
    
    bool inBound(Cell coor, vector<vector<bool>> &grid) {
        int m = grid.size(), n = grid[0].size();
        return coor.x >= 0 && coor.x < m && coor.y >= 0 && coor.y < n;
    }
};

// Conclusion:
// 标记连通岛屿的时候用BFS，而上一个版本是用DFS。
//
// Lintcode link:
// http://www.lintcode.com/zh-cn/problem/number-of-islands/
// http://www.jiuzhang.com/solutions/number-of-islands/





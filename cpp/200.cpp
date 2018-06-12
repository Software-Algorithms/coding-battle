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


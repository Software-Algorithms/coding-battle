/*
 * Solution 1:
 * BFS
 *
 */
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) return true;
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            if (t.first == destination[0] && t.second == destination[1]) return true;
            for (auto dir : dirs) {
                int x = t.first, y = t.second;
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0]; y += dir[1];
                }
                x -= dir[0]; y -= dir[1];
                if (!visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return false;
    }
};

// Conclusion:
//


/*
 * Solution 2:
 * DFS
 *
 */
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if (maze.empty() || maze[0].empty()) return true;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(maze, dp, start[0], start[1], destination[0], destination[1]);
    }
    bool helper(vector<vector<int>>& maze, vector<vector<int>>& dp, int i, int j, int di, int dj) {
        if (i == di && j == dj) return true;
        if (dp[i][j] != -1) return dp[i][j];
        bool res = false;
        int m = maze.size(), n = maze[0].size();
        maze[i][j] = -1;
        for (auto dir : dirs) {
            int x = i, y = j;
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
                x += dir[0]; y += dir[1];
            }
            x -= dir[0]; y -= dir[1];
            if (maze[x][y] != -1) {
                res |= helper(maze, dp, x, y, di, dj);
            }
        }
        dp[i][j] = res;
        return res;
    }
};

// version 2:
class Solution {  
public:  
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {  
        set<vector<int>> visited;  
        return DFS(maze, start, destination, visited);  
    }  
private:  
    bool DFS(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination, set<vector<int>> &visited) {  
        if(start == destination) {  
            return true;  
        }  
        if(visited.find(start) != visited.end()) {      // already visited  
            return false;  
        }  
        visited.insert(start);  
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  
        for(int i = 0; i < 4; ++i) {  
            vector<int> res = go2End(maze, start, dirs[i]);  
            if(res == destination || DFS(maze, res, destination, visited)) {  
                return true;  
            }  
        }  
        return false;  
    }  
    vector<int> go2End(vector<vector<int>> &maze, vector<int> start, vector<int> &dir) {  
        vector<int> new_start = {start[0] + dir[0], start[1] + dir[1]};  
        int row_num = maze.size(), col_num = maze[0].size();  
        if(new_start[0] < 0 || new_start[0] >= row_num || new_start[1] < 0 || new_start[1] >= col_num ||  
           maze[new_start[0]][new_start[1]] == 1) {  
            return start;  
        }  
        return go2End(maze, new_start, dir);  
    }  
};

// Conclusion:
//
// Reference:
// 2nd version: https://blog.csdn.net/magicbean2/article/details/78706612



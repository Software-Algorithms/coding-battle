/*
 * DP
 *
 */

// version 1:
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> v1(m, vector<int>(n, 0)), v2 = v1, v3 = v1, v4 = v1;
        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 'E') v1[i][0] = 1;
            for(int j = 1; j < n; j++) { // left -> right
                if(grid[i][j] == 'E') v1[i][j] = v1[i][j-1] + 1;
                else if(grid[i][j] == '0') v1[i][j] = v1[i][j-1];
                else v1[i][j] = 0;
            }
            if(grid[i][n-1] == 'E') v2[i][n-1] = 1;
            for(int j = n-2; j >= 0; j--) { // right -> left
                if(grid[i][j] == 'E') v2[i][j] = v2[i][j+1] + 1;
                else if(grid[i][j] == '0') v2[i][j] = v2[i][j+1];
                else v2[i][j] = 0;                
            }
        }
        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 'E') v3[0][j] = 1;
            for(int i = 1; i < m; i++) { // up -> down
                if(grid[i][j] == 'E') v3[i][j] = v3[i-1][j] + 1;
                else if(grid[i][j] == '0') v3[i][j] = v3[i-1][j];
                else v3[i][j] = 0;
            }
            if(grid[m-1][j] == 'E') v4[m-1][j] = 1;
            for(int i = m-2; i >= 0; i--) { // down -> up
                if(grid[i][j] == 'E') v4[i][j] = v4[i+1][j] + 1;
                else if(grid[i][j] == '0') v4[i][j] = v4[i+1][j];
                else v4[i][j] = 0;                
            }
        }
        
        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '0') {
                    res = max(res, v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]);
                }
            }
        }
        return res;
    }
};

// version 2: concised
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> v1(m, vector<int>(n, 0)), v2 = v1, v3 = v1, v4 = v1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int t = (j == 0 || grid[i][j] == 'W') ? 0 : v1[i][j - 1];
                v1[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
            for (int j = n - 1; j >= 0; --j) {
                int t = (j == n - 1 || grid[i][j] == 'W') ? 0 : v2[i][j + 1];
                v2[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                int t = (i == 0 || grid[i][j] == 'W') ? 0 : v3[i - 1][j];
                v3[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
            for (int i = m - 1; i >= 0; --i) {
                int t = (i == m - 1 || grid[i][j] == 'W') ? 0 : v4[i + 1][j];
                v4[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    res = max(res, v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]);
                }
            }
        }
        return res;
    }
};

/*****
Conclusion:
我最开始想出的方法是建立四个累加数组v1, v2, v3, v4，其中v1是水平方向从左到右的累加数组，v2是水平方向
从右到左的累加数组，v3是竖直方向从上到下的累加数组，v4是竖直方向从下到上的累加数组，我们建立好这个累加
数组后，对于任意位置(i, j)，其可以炸死的最多敌人数就是v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]，
最后我们通过比较每个位置的累加和，就可以得到结果。

Reference:
Grandyang: http://www.cnblogs.com/grandyang/p/5599289.html
*****/






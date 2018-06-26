/*
 * DP
 *
 */
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty() || obstacleGrid[0].empty()) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        if(obstacleGrid[0][0] == 1) return 0;
        res[0][0] = 1;
        
        for(int i = 1; i < m; i++) {
            if(obstacleGrid[i][0] == 1) res[i][0] = 0;
            else if(obstacleGrid[i-1][0] == 0) res[i][0] = res[i-1][0];
        }
        for(int i = 1; i < n; i++) {
            if(obstacleGrid[0][i] == 1) res[0][i] = 0;
            else if(obstacleGrid[0][i-1] == 0) res[0][i] = res[0][i-1];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(obstacleGrid[i][j] == 1) res[i][j] = 0;
                else {
                    if(obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j-1] == 1) res[i][j] = res[i-1][j];
                    else if(obstacleGrid[i-1][j] == 1 && obstacleGrid[i][j-1] == 0) res[i][j] = res[i][j-1];
                    else if(obstacleGrid[i-1][j] == 0 && obstacleGrid[i][j-1] == 0) res[i][j] = res[i-1][j] + res[i][j-1];
                    else res[i][j] = 0;
                }
            }
        }
        return res[m-1][n-1];        
    }
};

// Conclusion:
//





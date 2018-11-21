/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - 序列型 DP
 *    - Initialization: 第一行和第一列都只有1种走法；
 *    - Transition:	从左边和上边过来
 *            	    dp[i][j] = dp[i-1][j] + dp[i][j-1]
 *
 * Complexity:
 *    Time: O(lgn)
 *
 */
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

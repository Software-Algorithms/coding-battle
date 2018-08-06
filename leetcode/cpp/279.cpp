/*
 * DP
 *
 */
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};

/*****
Conclusion:
动态规划
状态：f[i]表示i最少被分成几个完全平方数之和
转移方程： f[i] = min{f[i-j^2] + 1}

Reference:
Jiuzhang DP Lesson 4.
*****/





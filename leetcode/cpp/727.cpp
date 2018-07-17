/*
 * DP
 *
 */

class Solution {
public:
    string minWindow(string S, string T) {
        int m = T.size(), n = S.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j + 1;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (T[i - 1] == S[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        int start = 0, len = n + 1;
        for (int j = 1; j <= n; j++) {
            if (dp[m][j] != 0) {
                if (j - dp[m][j] + 1 < len) {
                    start = dp[m][j] - 1;
                    len = j - dp[m][j] + 1;
                }
            }
        }
        return len == n + 1 ? "" : S.substr(start, len);     
    }
};

// Conclusion:
// 用dynamic programing来做，dp[i][j]表示T[0, j]是S[0,i]的subsequence的起始index，
// 所以我们的目标函数就是min(i-dp[i][n-1]) for all i < m
//
// Example:
//    ∅  b  d
// ∅  0 -1 -1
// d  1 -1 -1
// b  2  1 -1
// d  3  1  1
//
// Reference:
// Leetcode solution: https://leetcode.com/problems/minimum-window-subsequence/solution/
// Grandyang: http://www.cnblogs.com/grandyang/p/8684817.html






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
 *
 * Complexity:
 *    Time: O(lgn)
 *
 */
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-2] + dp[i-1];
        }
        return dp[n];
    }
};

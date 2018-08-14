// Lintcde 563. Backpack V
// Problem description: https://www.lintcode.com/problem/backpack-v/description
// Problem solution: https://www.jiuzhang.com/solutions/backpack-v

/*
 * DP (Backpack)
 * 
 */

// version 1: 二维dp
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        int m = target, n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }  
        return dp[n][m];
    }
};

/*****
Idea:
状态变量：
    设f[i][w] = 用前i个物品有多少种方式拼出重量w
状态转移方程：
    f[i][w] = f[i-1][w] + f[i-1][w-A[i-1]]
初始条件:
    f[0][0] = 1: 0个物品可以有一种方式拼出重量0 – f[0][1..M] = 0: 0个物品不能拼出大于0的重量
边界情况:
    f[i-1][w-A[i-1]只能在w≥A[i-1]时使用

Reference:
Jiuzhang.
*****/

// version 2: 一维dp
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers
     * @param target: An integer
     * @return: An integer
     */
    int backPackV(vector<int> &nums, int target) {
        // write your code here
        int dp[target+1] = {0};
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = target; j >= 0; j--) {
                if (j >= nums[i]) dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};

/*****
Conclusion:

Idea:
当前物品i进入背包当前容量j装满的可能性是 容量j-nums[i]时的可能性， 对每个i累加得到 dp[j]
Function: dp[j] += dp[j-nums[i]];
*****/         





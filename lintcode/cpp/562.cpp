// Lintcde 562. Backpack IV
// Problem description: https://www.lintcode.com/problem/backpack-iv/description
// Problem solution: https://www.jiuzhang.com/solutions/backpack-iv

/*
 * DP (Backpack)
 * 
 */

// version 1:
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        int m = target, n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                int k = 0; 
                while(k * nums[i-1] <= j) {
                    dp[i][j] += dp[i-1][j-nums[i-1]*k];
                    k+=1;
                }
            } // for j
        } // for i    
        return dp[n][m];
    }
};

// Conclusion:
// • State:
// 		dp[i][S] “前i”个物品，取出一些能否组成和为S
// • Function:
// 		nums[i-1] 是第i个物品下标是i-1 • k 是第i个物品选取的次数
// 		dp[i][S] = dp[i-1][S - k*nums[i-1]] or dp[i-1][S]
// • Intialize:
// 		dp[i][0] = true; dp[0][1..target] = false
// • Answer:
// 		答案是dp[n][S]
//
// Reference:
// Jiuzhang 算法强化班。

// version 2:
class Solution {
public:
    /**
     * @param nums: an integer array and all positive numbers, no duplicates
     * @param target: An integer
     * @return: An integer
     */
    int backPackIV(vector<int> &nums, int target) {
        // write your code here
        vector<int> dp(target+1);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums[i]; j <= target; j++) {
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};

// Conclusion:
// Function: dp[j] += dp[j-nums[i]];
//           当前物品i进入背包当前容量j装满的可能性是 容量j-nums[i-1]时的可能性， 对每个i累加得到 dp[j]





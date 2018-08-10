// Lintcde 563. Backpack V
// Problem description: https://www.lintcode.com/problem/backpack-v/description
// Problem solution: https://www.jiuzhang.com/solutions/backpack-v

/*
 * DP (Backpack)
 * 
 */
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





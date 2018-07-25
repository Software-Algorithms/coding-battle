/*
 * DP
 * 
 */

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int>(n+2));
        for(int len = 1; len <= n; len++) {
            for(int left = 1; left <= n-len+1; left++) {
                int right = left + len - 1;
                for(int k = left; k <= right; k++) {
                    dp[left][right] = max(dp[left][right], nums[left-1]*nums[k]*nums[right+1] + dp[left][k-1] + dp[k+1][right]);
                }
            }
        }
        return dp[1][n];
    }
};

/*****
详细思路：
计算dp[i][j]的思路是依次假定i到j中某一个气球是最后燃烧的，比如说k（k在i到j之间）
是最后燃烧的，那么在这个假定成立的前提下，最大收益是
nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]

参考：
Leetcode Discuss: https://leetcode.com/problems/burst-balloons/discuss/76230/C++-dp-detailed-explanation
*****/





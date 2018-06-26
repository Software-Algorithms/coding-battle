/**
 * Recursion
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        helper(nums, S, 0, res);
        return res;
    }
    void helper(vector<int>& nums, int S, int start, int& res) {
        if (start >= nums.size()) {
            if (S == 0) ++res;
            return;
        }
        helper(nums, S - nums[start], start + 1, res);
        helper(nums, S + nums[start], start + 1, res);
    }
};


/**
 * Recursion + DP (use a hash table as memory)
 *
 * dp[i][j]: the number of ways when nums[i:end] and s == j
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<unordered_map<int, int>> dp(nums.size());
        return helper(nums, S, 0, dp);
    }
    int helper(vector<int>& nums, int sum, int start, vector<unordered_map<int, int>>& dp) {
        if (start == nums.size()) return sum == 0;
        if (dp[start].count(sum)) return dp[start][sum];
        int cnt1 = helper(nums, sum - nums[start], start + 1, dp);
        int cnt2 = helper(nums, sum + nums[start], start + 1, dp);
        return dp[start][sum] = cnt1 + cnt2;
    }
};


/**
 * Bottom-up DP
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(int i: nums) sum += i;
        if(S > sum || S < -sum) return 0;
        vector<int> dp(2*sum+1);
        dp[0+sum] = 1;
        for(int i = 0; i < nums.size(); i++){
            vector<int> next(2*sum+1);
            for(int k = 0; k < 2*sum+1; k++){
                if(dp[k] != 0){
                    next[k + nums[i]] += dp[k];
                    next[k - nums[i]] += dp[k];
                }
            }
            dp = next;
        }
        return dp[sum+S];
    }
};
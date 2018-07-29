/*
 * DP
 *
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int max_len = 1;
        vector<int> dp(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                dp[i] = dp[i-1] + 1;
                max_len = max(max_len, dp[i]);
            }
        }
        
        return max_len;
    }
};

/*****
Conclusion:
典型DP题LIS，序列型DP。
*****/





/*
 * Two Pointers (Slinding Window)
 *
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, anchor = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i-1] >= nums[i]) anchor = i;
            ans = max(ans, i - anchor + 1);
        }
        return ans;
    }
};

/*****
Conlusion:
套用Slinding Window模板。
Reference:
Leetcode Article: https://leetcode.com/articles/longest-continuous-increasing-subsequence/
*****/





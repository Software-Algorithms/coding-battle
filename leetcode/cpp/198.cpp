/*
 * DP
 *
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int pre = 0, cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            int temp = max(pre+nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

/*****
Conclusion:

Function: dp[i] = max(dp[i-1], dp[i-2] + nums[i])

Reference:
...
*****/





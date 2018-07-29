/*
 * DP
 *
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }
private:
    int robber(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};

/*****
Conclusion:

Idea:
把环切开，就变成I的问题。所有条件都一样，只不过首尾视作相邻。所有分成两个子问题：[0 -> n-2]  和 [1 - > n-1] 
Function: dp[i] = max(dp[i-1], dp[i-2] + nums[i])

Reference:
...
*****/





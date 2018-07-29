/*
 * DP
 *
 */
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int res = 0;
        vector<int> dp(envelopes.size(), 1);
        sort(envelopes.begin(), envelopes.end());
        for(int i = 0; i < envelopes.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

/*****
Conclusion:

Idea:
DP:
- State: dp[i]: 截至当前的子序列的最多值；
- Function: dp[i] = max(dp[i], dp[j] + 1)；
- Result: max(dp[i])

Time: O(n^2)

Reference:
Jiuzhang DP Lesson 3.
*****/





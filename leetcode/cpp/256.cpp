/**
 * DP
 */

// version 1:
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        vector<vector<int>> dp = costs;
        for (int i = 1; i < dp.size(); ++i) {
            dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
        }
        return min(min(dp.back()[0], dp.back()[1]), dp.back()[2]);
    }
};

// version 2:
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()){
            return 0;
        }
        
        int n = costs.size();
        for(int i=1; i<costs.size(); i++) {
            costs[i][0] += min(costs[i-1][1], costs[i-1][2]);
            costs[i][1] += min(costs[i-1][0], costs[i-1][2]);
            costs[i][2] += min(costs[i-1][1], costs[i-1][0]);
        }

        return min(min(costs[n-1][0], costs[n-1][1]), costs[n-1][2]);        
    }
};

/*****
Conclusion:
1. Trick 1: 使用多个dp数组；
2. Trick 2: 并不开辟新空间，而是使用原数组。
*****/





/**
 * DP
 */
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;

        int n = costs.size(), k = costs[0].size();
        // min1 is the index of the 1st-smallest cost till previous house
        // min2 is the index of the 2nd-smallest cost till previous house
        int min1 = -1, min2 = -1;

        for (int i = 0; i < n; i++) {
            int last1 = min1, last2 = min2;
            min1 = -1; min2 = -1;

            for (int j = 0; j < k; j++) {
                if (j != last1) {
                    // current color j is different to last min1
                    costs[i][j] += last1 < 0 ? 0 : costs[i - 1][last1];
                } else {
                    costs[i][j] += last2 < 0 ? 0 : costs[i - 1][last2];
                }

                // find the indices of 1st and 2nd smallest cost of painting current house i
                if (min1 < 0 || costs[i][j] < costs[i][min1]) {
                    min2 = min1; min1 = j;
                } else if (min2 < 0 || costs[i][j] < costs[i][min2]) {
                    min2 = j;
                }
            }
        }

        return costs[n - 1][min1];        
    }
};

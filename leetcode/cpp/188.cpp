/*
 * DP
 *
 */

// version 1: ?
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if( k<=0 || prices.empty() ) return 0;

        const int N(prices.size());
        
        if(k >= N-1){ 
            // Under this condition, we can add profit accumulatively
            int sum(0);
            for(int i = 1; i < N; i++) {
                sum += max(0, prices[i] - prices[i-1]);
            }
            return sum;
        } else {
            // Dynamic programming
            vector<int> buy(k, INT_MIN), sell(k, INT_MIN);
            for(int price : prices){
                for(int i = 0; i < k; i++){
                    buy[i] = max(buy[i], (i == 0 ? 0 - price : sell[i-1] - price));
                    sell[i] = max(sell[i], buy[i] + price);
                }
            }
            return sell[k-1];   
        }        
    }
};



// version 2:
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solveMaxProfit(prices);
        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 1; i < prices.size(); i++) {
            int diff = prices[i] - prices[i-1];
            for (int j = k; j >= 1; j--) {
                l[j] = max(g[j-1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }

private:
    int solveMaxProfit(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] - prices[i - 1] > 0) {
                res += prices[i] - prices[i - 1];
            }
        }
        return res;
    }
};

/*****
Conclusion:
Greedy + DP + 空间优化

空间优化：
利用二维滚动数组的性质，进行空间优化。原本使用二维数组，注意到l[j]的更新依赖于l[i-1],
所以可以从后往前更新，这样只需要一个一维数组。

Reference:
Grandyang.
*****/





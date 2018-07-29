/*
 * Greedy
 *
 */

// version 1:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int minPrice = prices[0]; // 峰谷
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            while(i < prices.size() && prices[i] > prices[i-1]) i++;
            profit = profit+prices[i-1]-minPrice; // prices[i-1] 是峰顶
            if(i < prices.size()) minPrice = prices[i];
        }
        return profit;        
    }
};

// version 2:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int min_price = prices[0];
        int profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }
        return profit;
    }
};

/*****
Conclusion:
这题不同于I，不是用DP，而是Greedy，放这里主要是为了对照。
*****/





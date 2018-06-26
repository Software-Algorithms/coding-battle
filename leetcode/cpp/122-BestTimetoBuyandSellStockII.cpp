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
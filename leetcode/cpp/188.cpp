class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if( k<=0 || prices.empty() ) return 0;
        const int N(prices.size());
        
        if(k>=N-1){ 
            // Under this condition, we can add profit accumulatively
            int sum(0);
            for(int i=1;i<N;++i){
                sum += std::max(0,prices[i]-prices[i-1]);
            }
            return sum;
        } else {
            // Dynamic programming
            vector<int> buy(k,INT_MIN), sell(k,INT_MIN);
            for(int price : prices){
                for(int i=0; i<k; ++i){
                    buy[i] = std::max(buy[i], (i==0? 0-price : sell[i-1]-price) );
                    sell[i] = std::max(sell[i], buy[i] + price);
                }
            }
            return sell[k-1];   
        }        
    }
};
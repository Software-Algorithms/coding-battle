/*
 * DP
 *
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for(int i = 0; i < prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

/*****
Conclusion:

Idea:
原始DP四要素：
1) 状态
dp1[i]: 以结尾i结尾的[0:i]的子数组的最小值
dp2[i]: 以结尾i结尾的[0:i]的子数组的最大获利值
2）初始化
Initialization: dp2[0] = 0
3）转移方程
Function: dp2[i] = max(dp2[i-1], prices[i] - dp1[i-1])
4）结果
dp2[n-1]
或者简单来说，就是时刻记录当前最小值，更新max（当前价格 - 最小价格），最后就是结果。
*****/





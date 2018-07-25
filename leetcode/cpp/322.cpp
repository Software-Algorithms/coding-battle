/*
 * Solution 1: DP
 *
 */

// version 1:
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(i >= coin && dp[i-coin] != INT_MAX) dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// version 2:
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++) {
            for(auto & c : coins) {
                if(i-c >= 0 && dp[i-c] != -1) {
                    dp[i] = dp[i] > 0 ? min(dp[i], dp[i-c]+1) : dp[i-c]+1;
                }
            }
        }
        
        return dp[amount];
    }
};

// 思路：
// 对于求极值问题，我们还是主要考虑动态规划Dynamic Programming来做，我们维护一个一维动态数组dp，其中dp[i]表示钱数为i时的最小硬币数的找零，递推式为：
// dp[i] = min(dp[i], dp[i - coins[j]] + 1);
// 其中coins[j]为第j个硬币，而i - coins[j]为钱数i减去其中一个硬币的值，剩余的钱数在dp数组中找到值，然后加1和当前dp数组中的值做比较，取较小的那个更新dp数组。

/*************************
详细思路：

分而化之，一个一个面额的来。
就以样例为例：
字义一个amount数组[0, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]，大小为amount+1
代表可以组成某种金额的最少纸币数量的数组(好好体会)。例如amount[5] = inf
即：可以组成5分钱的最少纸币数量为inf（无限大）（为什么是无限大而不是0呢，这是因为动态转移方程中涉及到min操作，如果是0会造成错误）
为什么第一个元素为0呢，这代表我们一张也不选，这种方法可以组成0分钱。

先只考虑1分钱，于是变成[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
即要组成8分钱，肯定需要8张1分的，要组成11分，肯定需要11张1分的。

再考虑加上2分钱呢？
于是变成[0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6]
即要组成7分钱，amount[7]=3 代表三种方法：1+1+1+1+1+1+1=7、1+2+2+2=7、1+1+1+2+2=7.

再加上5分钱呢？
变成[0, 1, 1, 2, 2, 1, 2, 2, 3, 3, 2, 3]

依此类推。
转移方程为dp[j] = min(dp[j], dp[j - i] + 1)
d[j] 为组成某种金额的最小数量，i为当前新的钱币的面额。

如果走完所有的金额，发现某个amount[i]竟然还是inf，这代表什么呢？
这说明这种面额根本组不成！！所以我们要返回-1
**************************/



/*
 *
 *
 */

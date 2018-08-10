// Lintcde 92. Backpack
// Problem description: https://www.lintcode.com/problem/backpack/description
// Problem solution: https://www.jiuzhang.com/solutions/backpack

/*
 * Solution 1: DP (Backpack)
 * 
 */

// version 1:
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

        dp[0][0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= A[i-1] && dp[i-1][j - A[i-1]]) {
                    dp[i][j] = true;
                }
        }
        
        for (int i = m; i >= 0; i--) {
            if (dp[n][i]) {
                return i;
            }
        }
        
        return 0;
    }
};

/*****
Conclusion:
• State:
	dp[i][S] “前i”个物品，取出一些能否组成和为S
• Function:
    a[i-1] 是第i个物品下标是i-1
		dp[i][S] = dp[i-1][S - a[i-1]] or dp[i-1][S]
• Intialize:
		dp[i][0] = true; f[0][1..target] = false
• Answer:
		检查所有的 dp[n][j]
• O(n*S) ， 滚动数组优化

Reference:
Jiuzhang.
*****/

/*
 * Solution 2: DP (Backpack)
 *
 */

// version 1: 这是基本款！
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        int dp[n+1][m+1];
        
        // Build table K[][] in bottom up manner
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (A[i-1] <= j) {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + A[i-1]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][m];
    }
};

// version 2:
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> &A) {
        // write your code here
        int n = A.size();
        vector<int> dp(m+1);
        for (int i = 0; i < n; i++) {
            for (int j = m; j > 0; j--) {
                if (j >= A[i]) {
                    dp[j] = max(dp[j], dp[j-A[i]] + A[i]);
                }
            }
        }
        return dp[m];
    }
};

/*****
Conclusion:
这一题是经典的0-1背包问题（0-1 Knapsack Problem / 0-1 Backpack Problem）。
可以用二维滚动数组解决，如version 1，version 2在version 1的基础上，进行空间优化，因为每一行仅与上一行相关，可以用一个
一维数组在本地更新，注意这时要从后往前更新，因为每一位置上的更新依赖于前面的值。

Idea:
用数组dp[i]表示书包空间为i的时候能装的A物品最大容量。两次循环，外部遍历数组A，内部反向遍历数组dp，若j即背包容量大于等于物
品体积A[i]，则取前i-1次循环求得的最大容量dp[j]，和背包体积为j-A[i]时的最大容量dp[j-A[i]]与第i个物品体积A[i]之和即
dp[j-A[i]]+A[i]的较大值，作为本次循环后的最大容量dp[i]。

Note: 注意dp[]的空间要给m+1，因为我们要求的是第m+1个值dp[m]，否则会抛出OutOfBoundException。
 
dp[i]: 书包空间为i的时候能装的A物品最大容量
function:
    max(前i-1次循环求得的最大容量dp[j], 背包体积为j-A[i]时的最大容量dp[j-A[i]]与第i个物品体积A[i]之和即 dp[j-A[i]]+A[i])

Reference:
[LintCode] Backpack I II III IV V VI [背包六问] -- https://segmentfault.com/a/1190000006325321
*****/





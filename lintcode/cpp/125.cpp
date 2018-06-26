// Lintcde 125. Backpack II
// Problem description: https://www.lintcode.com/problem/backpack-ii/description
// Problem solution: https://www.jiuzhang.com/solutions/backpack-ii

/*
 * DP (Backpack)
 * 
 */
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                } else if (A[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + V[i-1]);
                }
            }
        }
        return dp[n][m];
    }
};

// Conclusion:
// • 状态 State
//      dp[i][j] 表示前i个物品当中选一些物品组成容量为j的最大价值
// • 方程 Function
//      dp[i][j] = max(dp[i-1][j], dp[i-1][j-A[i-1]] + V[i-1]);
// • 初始化 Intialization
//      dp[0][0]=0;
// • 答案 Answer
//      dp[n][s]
// • O(n*s)
//
// Reference:
// Jiuzhang 算法强化班。
//

// version 2:


// Conclusion:
// 和BackPack I基本一致。依然是以背包空间为限制条件，所不同的是dp[j]取的是价值较大值，
// 而非体积较大值。所以只要把dp[j-A[i]]+A[i]换成dp[j-A[i]]+V[i]就可以了。
//
// Reference:
// [LintCode] Backpack I II III IV V VI [背包六问] -- https://segmentfault.com/a/1190000006325321









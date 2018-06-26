// Lintcode 476. Stone Game
// Problem description: https://www.lintcode.com/problem/stone-game/description
// Problem solution: https://www.jiuzhang.com/solutions/stone-game

/*
 * DP (区间型DP)
 *
 */

// version 1: 记忆化搜索
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        if (A.empty()) return 0;
        
        int n = A.size();
        
        // initialize
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> visit(n, vector<int>(n));
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        
        // preparation
        vector<vector<int>> sum(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            sum[i][i] = A[i];
            for (int j = i + 1; j < n; j++) {
                sum[i][j] = sum[i][j - 1] + A[j];
            }
        }
        
        return search(0, n-1, dp, visit, sum);
    }
    
private:
    int search(int l, int r, vector<vector<int>>& dp, vector<vector<int>>& visit, vector<vector<int>>& sum) {
        if(visit[l][r] == 1) return dp[l][r];
        if(l == r) {
            visit[l][r] = 1;
            return dp[l][r];
        }
        
        dp[l][r] = INT_MAX;
        for (int k = l; k < r; k++) {
            dp[l][r] = min(dp[l][r], search(l, k, dp, visit, sum)
                                     + search(k + 1, r, dp, visit, sum)
                                     + sum[l][r]);
        }
        visit[l][r] = 1;
        return dp[l][r];
    }
};

// version 2: concised
class Solution {
public:
    /**
     * @param A: An integer array
     * @return: An integer
     */
    int stoneGame(vector<int> &A) {
        // write your code here
        if(A.empty()) return 0;

        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        vector<int> sums(n+1);
        
        for(int i = 0; i < n; i++) {
            dp[i][i] = 0;
            sums[i+1] = sums[i] + A[i];
        }
        
        return search(0, n-1, dp, sums);
    }

private:    
    int search(int start, int end, vector<vector<int>>& dp, vector<int>& sums){
        if(dp[start][end] != INT_MAX){
            return dp[start][end];
        }
        int mn = INT_MAX;
        for(int k = start; k < end; k++) {
            int left = search(start, k, dp, sums);
            int right = search(k+1, end, dp, sums);
            int now = sums[end+1] - sums[start];
            mn = min(mn, left+right+now);
        }
        dp[start][end] = mn;
        return mn;
    }
};

// Conclusion:
//
// Reference:
// Jiuzhang 算法强化班。
//





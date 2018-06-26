// 398. Longest Increasing Continuous subsequence II
// Prolblem description: http://www.lintcode.com/problem/longest-increasing-continuous-subsequence-ii/
// Problem solution: https://www.jiuzhang.com/solutions/longest-increasing-continuous-subsequence-ii

/*
 * DP + DFS
 *
 */

const int dirx[4] = {0, 0, 1, -1};
const int diry[4] = {1, -1, 0, 0};

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        if(A.empty() || A[0].empty()) return 0;
        
        maxx = 0;
        m = A.size(), n = A[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dis[i][j] =0;
            }
        }
       
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dis[i][j] == 0) {
                    dfs(i, j , 0, A);
                }
            }
         }

        return maxx;
    }
    
private:
    int m, n;
    int dis[200][200];
    int maxx;

    void dfs(int x,int y,int depth, vector<vector<int>>& a) {
        int nowdepth = depth;
        if ((++nowdepth) > dis[x][y]) { 
            dis[x][y] = nowdepth;
            if (dis[x][y] > maxx) maxx = dis[x][y];
        } else {
            return;
        }
 
        int nowx,nowy;
        for (int i=0;i < 4; ++i) {
            nowx = x + dirx[i];
            nowy = y + diry[i];
            if (nowx < 0 || nowx >= n || nowy < 0 || nowy >= m) continue;
            if (a[nowx][nowy] <= a[x][y]) continue;  
            dfs(nowx, nowy, nowdepth, a);
        }
    }
};

// Conclusion:
//
//
//





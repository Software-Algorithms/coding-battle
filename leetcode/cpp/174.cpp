class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty()) {
            return 0;
        }
        else {
            int m = dungeon.size(), n = dungeon[0].size();
            vector<vector<int>> memo(m, vector<int>(n));
            memo[m-1][n-1] = dungeon[m-1][n-1] > 0 ? 1 : 1 - dungeon[m-1][n-1];
            for (int i = m-1; i >= 0; i --) {
                for (int j = n-1; j >= 0; j--) {
                    if (i == m-1 && j == n-1) { 
                        continue;
                    }
                    
                    int right = (j == n-1) ? INT_MAX : memo[i][j+1], down = (i == m-1) ?  INT_MAX : memo[i+1][j];
                    int minMove = min(right,down);
                    
                    if (dungeon[i][j] < 1) {
                        memo[i][j] = minMove - dungeon[i][j];
                    }
                    else {
                        memo[i][j] = minMove -dungeon[i][j] < 1 ? 1 : minMove - dungeon[i][j];
                    }
                }
            }
            return memo[0][0];
        }        
    }
};
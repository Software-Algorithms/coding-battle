// Lintcode 598. Zombie in Matrix
// https://www.lintcode.com/problem/zombie-in-matrix/description
// https://www.jiuzhang.com/solutions/zombie-in-matrix

/*
 * BFS in Matrix
 *
 */
class Solution {
public:
    /**
     * @param grid: a 2D integer grid
     * @return: an integer
     */
    int zombie(vector<vector<int>> &grid) {
        // write your code here
        if(grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        int days = -1;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(!q.empty()) {
            int len = q.size();
            days++;
            for(int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int x = t.first + dirs[k][0], y = t.second + dirs[k][1];
                    if(x < 0 || x >=m || y < 0 || y >= n || grid[x][y] != 0) continue;
                    grid[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    return -1;
                }
            }
        }
        
        return days;
    }
};

// Conclusion:
// 有些时候矩阵本身就可以起到记忆矩阵的作用，而无需另外定义一个记忆搜索矩阵，如本题中，矩阵的元素值可以作为检查标志位。





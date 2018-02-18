class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    drownIslands(grid, i, j);
                    count++;
                }
            }
        }
        return count;        
    }

    void drownIslands(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] == '0') return;
        grid[x][y] = '0';
        drownIslands(grid, x-1, y);
        drownIslands(grid, x+1, y);
        drownIslands(grid, x, y-1);
        drownIslands(grid, x, y+1);
        return;
    }
};
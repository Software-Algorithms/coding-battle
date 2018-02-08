class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n < 0) return vector<vector<int>>();
        
        vector<vector<int>> res(n, vector<int>(n));
        
        int start = 1, x = 0, y = 0;
        for(int i = n; i > 0; i -= 2) {
            if(i == 1){
                res[x][y] = start;
            } else {
                for(int j = 0; j < i-1; j++){
                    res[x][y++] = start++;   
                }
                for(int j = 0;j < i-1; j++){
                    res[x++][y] = start++;
                }
                for(int j = 0; j < i-1; j++){
                    res[x][y--] = start++;
                }
                for(int j = 0; j < i-1; j++){
                    res[x--][y] = start++;
                }
                x++;
                y++;
            }
        }
        return res;        
    }
};
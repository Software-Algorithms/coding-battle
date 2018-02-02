class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> nums;
        // check each row
        for(int i = 0; i < 9; i++) {
            nums = {0,0,0,0,0,0,0,0,0,0};
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int n = board[i][j] - '0';
                    nums[n]++;
                    if(nums[n]>1) return false;
                }
            }
        }
 
        //check each column
        for(int i = 0; i < 9; i++) {
            nums = {0,0,0,0,0,0,0,0,0,0};
            for(int j = 0; j < 9; j++) {
                if(board[j][i] != '.') {
                    int n = board[j][i] - '0';
                    nums[n]++;
                    if(nums[n]>1) return false;
                }
            }
        }
 
        // check each sub-box
        for(int i = 0; i < 9; i++) {
            int irow = i/3*3;
            int icol = i%3*3;
            nums = {0,0,0,0,0,0,0,0,0,0};
            for(int j = irow; j < irow+3; j++) {
                for(int k = icol; k < icol+3; k++) {
                    if(board[j][k] != '.') {
                        int n = board[j][k] - '0';
                        nums[n]++;
                        if(nums[n]>1) return false;
                    }
                }
            }
        }
        return true;        
    }
};
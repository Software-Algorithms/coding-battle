class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        std::vector<std::string> nQueens(n, std::string(n, '.'));
        solveNQueens(count, nQueens, 0, n);
        return count;        
    }
    
private:
    void solveNQueens(int& count, std::vector<std::string> &nQueens, int row, int &n) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col != n; ++col)
            if (isValid(nQueens, row, col, n)) {
                nQueens[row][col] = 'Q';
                solveNQueens(count, nQueens, row + 1, n);
                nQueens[row][col] = '.';
            }
    }
    
    bool isValid(std::vector<std::string> &nQueens, int row, int col, int &n) {
        //check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (nQueens[i][col] == 'Q')
                return false;
        //check if the 45° diagonal had a queen before.
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (nQueens[i][j] == 'Q')
                return false;
        //check if the 135° diagonal had a queen before.
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (nQueens[i][j] == 'Q')
                return false;
        return true;
    }
};
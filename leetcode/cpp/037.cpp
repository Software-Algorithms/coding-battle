/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *
 * Complexity:
 *    Time: O(?)
 *
 */
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

private:
    int N = 9;

    bool solve(vector<vector<char>>& board) {
        int row, col;

        if(!findUnassignedCell(board, row, col))
            return true;

        for(int num = 1; num <= 9; num++) {
            if(isAssignedSafe(board, row, col, num)) {
                board[row][col] = '0'+num;
                if(solve(board)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    bool findUnassignedCell(vector<vector<char>>& board, int& row, int& col) {
        for(row = 0; row < N; row++) {
            for(col = 0; col < N; col++) {
                if(board[row][col] == '.') {
                    return true;
                }
            }
        }
        return false;
    }

    bool isAssignedSafe(vector<vector<char>>& board, int row, int col, int assigned) {
        if(!isUsedInRow(board, row, assigned) &&
           !isUsedInCol(board, col, assigned) &&
           !isUsedInBox(board, row-row%3, col-col%3, assigned)) {
            return true;
        }
        return false;
    }

    bool isUsedInRow(vector<vector<char>>& board, int row, int num) {
        for(int i = 0; i < N; i++) {
            if(board[row][i] == '0'+num) return true;
        }
        return false;
    }

    bool isUsedInCol(vector<vector<char>>& board, int col, int num) {
        for(int i = 0; i < N; i++) {
            if(board[i][col] == '0'+num) return true;
        }
        return false;
    }

    bool isUsedInBox(vector<vector<char>>& board, int startRow, int startCol, int num) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[startRow+i][startCol+j] == '0'+num) return true;
            }
        }
        return false;
    }
};

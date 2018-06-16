/*
 * DFS
 *
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty()) return false;
        
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isFound(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool isFound(vector<vector<char>>& board, string word, int idx, int x, int y) {
        if(x < 0 || x > board.size()-1 || y < 0 || y > board[0].size()-1) return false;
        if(board[x][y] == '\0' || word[idx] != board[x][y]) return false;
        if(idx == word.size()-1) return true;
        char temp = board[x][y];
        board[x][y] = '\0';
        if(isFound(board, word, idx+1, x-1, y) || isFound(board, word, idx+1, x+1, y)
                || isFound(board, word, idx+1, x, y-1) || isFound(board, word, idx+1, x, y+1)) {
                    return true;
                }
        board[x][y] = temp;
        return false;
    }
};

// Conclusion:
// How to distinguish dfs and backtracking?
//
//




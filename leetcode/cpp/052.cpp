/**
 * Code description
 *
 * Author: xpharry
 * Date: 12/3/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Backtracking.
 *    - Solution 1.
 *    - Go row by row, and in each position, we need to check if the column, the
 *      45° diagonal and the 135° diagonal had a queen before.
 *    - 这种棋盘类的题目一般是回溯法, 依次放置每行的皇后。在放置的时候，要保持当前的状态为合法，
 *      即当前放置位置的同一行、同一列、两条对角线上都不存在皇后。
 *
 * Complexity:
 *    Time: T(n) = n*T(n-1) + O(n^2) ~ O(n!)
 *    Space: O(n)
 *
 * Take-away:
 *    - string initialization: string = str(n, '.') which is similar to vector
 *
 */

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


/**
 * Code description
 *
 * Author: xpharry
 * Date: 12/3/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Backtracking.
 *    - Solution 2.
 *    - 上述判断状态是否合法的函数还是略复杂，其实只需要用一个一位数组来存放当前皇后的状态。假
 *      设数组为int state[n], state[i]表示第 i 行皇后所在的列。那么在新的一行 k 放置一个
 *      皇后后:
 *      > 判断列是否冲突，只需要看state数组中state[0…k-1] 是否有和state[k]相等；
 *      > 判断对角线是否冲突：如果两个皇后在同一对角线，那么
 *        |row1-row2| = |column1 - column2|，
 *       （row1，column1），（row2，column2）分别为冲突的两个皇后的位置
 *
 * Complexity:
 *    Time: T(n) = n*T(n-1) + O(n^2) ~ O(n!)
 *    Space: O(n)
 *
 * Reference:
 *    http://www.cnblogs.com/TenosDoIt/p/3801621.html
 *
 */

class Solution {
private:
    vector<vector<string> > res;
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> state(n, -1);
        helper(state, 0);
        return res;
    }

    void helper(vector<int> &state, int row) { // 放置第row行的皇后
        int n = state.size();
        if(row == n) {
            vector<string>tmpres(n, string(n,'.'));
            for(int i = 0; i < n; i++)
                tmpres[i][state[i]] = 'Q';
            res.push_back(tmpres);
            return;
        }
        for(int col = 0; col < n; col++)
            if(isValid(state, row, col)) {
                state[row] = col;
                helper(state, row+1);
                state[row] = -1;;
            }
    }

    // 判断在row行col列位置放一个皇后，是否是合法的状态
    // 已经保证了每行一个皇后，只需要判断列是否合法以及对角线是否合法。
    bool isValid(vector<int> &state, int row, int col) {
        for(int i = 0; i < row; i++)//只需要判断row前面的行，因为后面的行还没有放置
            if(state[i] == col || abs(row - i) == abs(col - state[i]))
                return false;
        return true;
    }
}

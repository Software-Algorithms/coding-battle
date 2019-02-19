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
 *    - Go row by row, and in each position, we need to check if the column, the
 *      45° diagonal and the 135° diagonal had a queen before.
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
     vector<vector<string>> solveNQueens(int n) {
         vector<vector<string>> sols;
         vector<string> sol(n, string(n, '.'));

         backtracking(0, n, sol, sols);

         return sols;
     }

     void backtracking(int row, int n, vector<string> &sol, vector<vector<string>> &sols) {
         if(row == n) {
             sols.push_back(sol);
             return;
         }

         for(int col = 0; col < n; col++) {
             if(isValid(sol, row, col, n)) {
                 sol[row][col] = 'Q';
                 backtracking(row+1, n, sol, sols);
                 sol[row][col] = '.';
             }
         }
     }

     bool isValid(vector<string> &sol, int row, int col, int n) {
         // col
         for(int i = 0; i < row; i++) {
             if(sol[i][col] == 'Q') return false;
         }

         // 45 deg
         for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
             if(sol[i][j] == 'Q') return false;
         }

         // 135 deg
         for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
             if(sol[i][j] == 'Q') return false;
         }

         return true;
     }
 };

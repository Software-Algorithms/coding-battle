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
 *    - 2D Array / Matrix.
 *
 * Complexity:
 *    Time: O(n^2)
 *
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();
        // up and down: (i, j) <---> (n-1-i, j)
        for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = temp;
            }
        }
        // diagonal: (i,j) <---> (j,i)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};

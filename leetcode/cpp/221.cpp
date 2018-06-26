/**
 * DP
 *
 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m, vector<int>(n));
        for (int i = 0; i < n; ++i) f[0][i] = matrix[0][i] == '1';
        for (int i = 1; i < m; ++i) f[i][0] = matrix[i][0] == '1';
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == '0') continue;
                f[i][j] = 1 + min(f[i-1][j], min(f[i-1][j-1], f[i][j-1]));
            }
        int ans = 0;        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) ans = max(ans, f[i][j]);
        return ans*ans;        
    }
};

// Conclusion:
//





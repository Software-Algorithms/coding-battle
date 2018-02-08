class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        int height[n], left[n], right[n];
        fill_n(height, n, 0);
        fill_n(left, n, 0);
        fill_n(right, n, n-1);
        
        int maxArea = 0;
        for(int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n-1;
            // (1) update height[i]
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }
            
            // (2) update left[i]
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    left[j] = max(left[j],cur_left);
                } else {
                    left[j] = 0; // go back to left most
                    cur_left = j+1;
                }                
            }            
            
            // (3) update right[i]
             for(int j = n-1; j >= 0; j--) {
                if(matrix[i][j] == '1') {
                    right[j] = min(right[j],cur_right);
                } else {
                    right[j] = n-1; // go back to right most
                    cur_right = j-1;
                }                 
            }           
            // update maxArea
            for(int j = 0; j < n; j++) {
                maxArea = max(maxArea, (right[j]-left[j]+1)*height[j] );
            }
        }
        
        return maxArea;
    }
};
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        if (matrix[0].size() == 0) return false;
        int height = matrix.size();
        int width = matrix[0].size();
        int length = width * height;
        int l = 0, r = length-1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (target == matrix[mid/width][mid%width]) return true;
            if (target < matrix[mid/width][mid%width]) {
                r = mid-1;
            } else {
                l = mid+1;
            }
        }
        return false;        
    }
};
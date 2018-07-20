/*
 * Binary Search
 *
 */
class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = int(image.size()), n = int(image[0].size());
        int top = searchRows(image, 0, x, 0, n, true);
        int bottom = searchRows(image, x + 1, m, 0, n, false);
        int left = searchColumns(image, 0, y, top, bottom, true);
        int right = searchColumns(image, y + 1, n, top, bottom, false);
        return (right - left) * (bottom - top);
    }
    
    int searchRows(vector<vector<char>>& image, int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && image[mid][k] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
    
    int searchColumns(vector<vector<char>>& image, int i, int j, int low, int high, bool opt) {
        while (i != j) {
            int k = low, mid = (i + j) / 2;
            while (k < high && image[k][mid] == '0') ++k;
            if (k < high == opt)
                j = mid;
            else
                i = mid + 1;
        }
        return i;        
    }
};

// Reference:
// Leetcode Discuss: https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/discuss/75127/C++JavaPython-Binary-Search-solution-with-explanation






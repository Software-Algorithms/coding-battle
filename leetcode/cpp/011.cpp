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
 *    - Two Pointers.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int water = 0;
        int i = 0, j = height.size()-1;
        while(i < j) {
            if(height[i] < height[j]) {
                water = max(water, (j-i)*height[i]);
                i++;
            } else {
                water = max(water, (j-i)*height[j]);
                j--;
            }
        }
        return water;
    }
};

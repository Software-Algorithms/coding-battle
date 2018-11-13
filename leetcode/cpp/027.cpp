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
 *    Time: O(n)
 *
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) nums[count++] = nums[i];
        }
        return count;
    }
};

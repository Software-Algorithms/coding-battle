/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/12/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Version 1.
 *    - 找寻规律：
 *      如果数组元素值正确的话，应满足：nums[i] == i+1。如果可以把所有元素值还原到其符合要求
 *      的位置上，那么就可以从小往大搜寻到最小那个不合要求的值，也就是missing positive。
 *      所以关键操作是位置还原：swap(nums[i], nums[nums[i]-1])，要注意循环条件是
 *     （a）nums[i]-1要在下标范围内，（b）交换的两边值不相等，否则会陷入无限循环。同时，
 *      nums[i] != nums[nums[i]-1]这个条件也包含了i+1 != nums[i] 。
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i]-1 >= 0 && nums[i]-1 < nums.size() && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i != nums[i]-1) {
                return i+1;
            }
        }

        return nums.size()+1;
    }
};


/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/12/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Version 2.
 *    - Same idea.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n) {
            if(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            } else {
                ++i;
            }
        }
        for(i = 0; i < n; i++) {
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};

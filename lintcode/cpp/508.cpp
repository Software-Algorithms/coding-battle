// Lintcode 508. Wiggle Sort
// Problem description: https://lintcode.com/problem/wiggle-sort/description
// Problem solution: https://jiuzhang.com/solutions/wiggle-sort

/*
 * Array, Sort
 *
 */
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        if (nums.size() <= 1) return;
        for (int i = 1; i < nums.size(); ++i) {
            if ((i % 2 == 1 && nums[i] < nums[i - 1]) || (i % 2 == 0 && nums[i] > nums[i - 1])) {
                swap(nums[i], nums[i - 1]);
            }
        }
    }
};

// Conclusion:
//
//
// Reference:
//
//






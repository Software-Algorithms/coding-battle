/*
 * Binary Search
 * O(lgn)
 *
 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r) {
            int mid = l + (r-l) / 2;
            if(nums[mid] > nums[mid+1]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return r;
    }
};

// Conclusion:
// How to choose between mid and mid+1(or mid-1) ?
//

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1;
        int mid;
        
        while(lo<=hi) {
            mid = (hi-lo)/2 + lo;
            if(nums[mid] == target) return true;
            if(nums[mid] > nums[lo]) {
                if(target >= nums[lo] && target < nums[mid]) {
                    hi = mid - 1;
                } else {
                    lo = mid;
                }
            } else if(nums[mid] < nums[lo]) {
                if(target > nums[mid] && target <= nums[hi]) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }                
            } else {
                lo++;
            }
        }
        
        return false;        
    }
};
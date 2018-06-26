class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0];
        for(int i = 1, imax = nums[0], imin = nums[0]; i < nums.size(); ++i) {
            if(nums[i] < 0) {
                swap(imax, imin);
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            maxPro = max(imax, maxPro);
        }
        return maxPro;
    }
};
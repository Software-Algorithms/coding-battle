/**
 * Two Pointers
 */
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for(int i = 0; i < nums.size()-2; i++) {
            int lf = i+1, rh = nums.size()-1;
            while(lf < rh) {
                if(nums[i] + nums[lf] + nums[rh] < target) {
                    res += rh-lf;
                    lf++;
                } else {
                    rh--;
                }
            }
        }
        return res;
    }
};
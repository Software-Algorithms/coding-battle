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
 *    - Avoid repeatation.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i-1] == nums[i]) continue;
            int l = i+1, r = nums.size()-1;
            while(l < r) {
                if(l > i+1 && nums[l-1] == nums[l]) {l++; continue;}
                if(r < nums.size()-1 && nums[r] == nums[r+1]) {r--; continue;}
                if(nums[l] + nums[r] == -nums[i]) {
                    vector<int> triplets(3,0);
                    triplets[0] = nums[i];
                    triplets[1] = nums[l];
                    triplets[2] = nums[r];
                    res.push_back(triplets);
                    l++;
                    r--;
                } else if(nums[l] + nums[r] < -nums[i]) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return res;
    }
};

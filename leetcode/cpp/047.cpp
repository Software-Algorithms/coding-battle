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
 *    - DFS.
 *    - Avoid repeatation.
 *
 * Complexity:
 *    Time: O(?)
 *
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allPer;
        if(nums.empty()) return allPer;
        sort(nums.begin(),nums.end());
        vector<int> per;
        vector<bool> used(nums.size(),false);
        findPerUniq(nums, used, per, allPer);
        return allPer;
    }

    void findPerUniq(vector<int> &nums, vector<bool> &used, vector<int> &per, vector<vector<int>> &allPer) {
        if(per.size() == nums.size()) {
            allPer.push_back(per);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && used[i-1]) continue;
            used[i] = true;
            per.push_back(nums[i]);
            findPerUniq(nums, used, per, allPer);
            per.pop_back();
            used[i] = false;
        }
    }
};

/*
 * Backtracking
 *
 * Time: O(n*2^n)  Space: O(2^n)
 *
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> allSets;
        vector<int> sol;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, sol, allSets);
        return allSets;
    }
    
    void findSubsets(vector<int> &nums, int start, vector<int> &sol, vector<vector<int>> &allSets) {
        allSets.push_back(sol);
        for(int i=start; i<nums.size(); i++) {
            if(i>start && nums[i] == nums[i-1]) continue;
            sol.push_back(nums[i]);
            findSubsets(nums, i+1, sol, allSets);
            sol.pop_back();
        }
    }
};
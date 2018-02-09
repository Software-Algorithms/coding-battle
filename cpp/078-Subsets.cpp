/*
 * Backtracking
 *
 * Time: O(n*2^n)  Space: O(2^n)
 *
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSets;
        vector<int> sol;
        sort(nums.begin(),nums.end());
        findSubsets(nums, 0, sol, allSets);
        return allSets;
    }
    
    void findSubsets(vector<int> &nums, int start, vector<int> &sol, vector<vector<int>> &allSets) {
        allSets.push_back(sol);
        for(int i=start; i<nums.size(); i++) {
            sol.push_back(nums[i]);
            findSubsets(nums, i+1, sol, allSets);
            sol.pop_back();
        }
    }
};


/*
 * Bit Manipulation
 *
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int nSubsets = pow(2, n);

        vector<vector<int>> res(nSubsets, vector<int>());
        for(int i = 0; i < n; i++) { // for each element in the input array
            for(int j = 0; j < nSubsets; j++) { // for each subset
                if((j>>i)&1) res[j].push_back(nums[i]);
            }
        }

        return res;
    }
};
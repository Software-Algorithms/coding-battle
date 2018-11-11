class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPer;
        if(nums.empty()) return allPer;
        vector<bool> used(nums.size(), false);
        vector<int> per;
        findPermutations(nums, used, per, allPer);
        return allPer;
    }
    
    void findPermutations(vector<int> &nums, vector<bool> &used, vector<int> &per, vector<vector<int>> &allPer) {
        if(per.size() == nums.size()) {
            allPer.push_back(per);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;
            used[i] = true;
            per.push_back(nums[i]);
            findPermutations(nums, used, per, allPer);
            used[i] = false;
            per.pop_back();
        }        
    }
};
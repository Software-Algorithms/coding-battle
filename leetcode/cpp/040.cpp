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
 *    - DFS.
 *
 * Complexity:
 *    Time: O(?)
 *
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sols;
        vector<int> sol;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, sol, sols);
        return sols;
    }

    void dfs(vector<int>& candidates, int target, int start, vector<int>& sol, vector<vector<int>>& sols) {
        if(target == 0) {
            sols.push_back(sol);
            return;
        }
        if(target < 0) return;
        for(int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1]) continue;
            sol.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i+1, sol, sols);
            sol.pop_back();
        }
    }
};

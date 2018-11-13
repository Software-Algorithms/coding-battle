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
 *    - Backtracking.
 *
 * Complexity:
 *    Time: O(?)
 *
 */
 class Solution {
 public:
     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<int> sol;
         vector<vector<int>> sols;
         backtracking(candidates, target, 0, sol, sols);
         return sols;
     }

     void backtracking(vector<int>& candidates, int target, int index, vector<int>& sol, vector<vector<int>>& sols) {
         if(target == 0) {
             sols.push_back(sol);
             return;
         }
         if(target < 0) return;

         for(int i = index; i < candidates.size(); i++) {
             sol.push_back(candidates[i]);
             backtracking(candidates, target - candidates[i], i, sol, sols);
             sol.pop_back();
         }
     }
 };

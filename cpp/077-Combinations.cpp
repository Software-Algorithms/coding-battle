/*
 * Backtracking
 *
 * Time: O(n^2)
 *
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> allSol;
        vector<int> sol;
        helper(allSol, sol, 1, k, n);
        return allSol;
    }
    
    void helper(vector<vector<int>>& allSol, vector<int>& sol, int begin, int k, int n) {
        if(sol.size() == k) {
            allSol.push_back(sol);
            return;
        }
        for(int i = begin; i <= n; i++) {
            sol.push_back(i);
            helper(allSol, sol, i+1, k, n);
            sol.pop_back();
        }
    }
};
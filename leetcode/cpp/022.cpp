/*
 * backtracking
 *
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> sols;
        string sol;
        backtrackingFunc(sols, sol, n, n);
        return sols;
    }
    
    void backtrackingFunc(vector<string>& sols, string sol, int lefts, int rights) {
        if(lefts == 0 && rights == 0) {
            sols.push_back(sol);
            return;
        }
        if(lefts > 0) {
            backtrackingFunc(sols, sol+'(', lefts-1, rights);
        }
        if(rights > lefts) {
            backtrackingFunc(sols, sol+')', lefts, rights-1);
        }
    }
};


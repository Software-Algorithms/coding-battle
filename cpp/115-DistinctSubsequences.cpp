class Solution {
public:
    int numDistinct(string s, string t) {
        // array creation
        vector<vector<int>> mem(t.length()+1, vector<int>(s.length()+1));
    
        // filling the first row: with 1s
        for(int j = 0; j <= s.length(); j++) {
            mem[0][j] = 1; // because empty string is a subsequence for  every string
        }
        
        // the first column is 0 by default in every other rows but the first, which we need.
        for(int i = 0; i < t.length(); i++) {
            for(int j = 0; j < s.length(); j++) {
                if(t[i] == s[j]) {
                    mem[i+1][j+1] = mem[i][j] + mem[i+1][j];
                } else {
                    mem[i+1][j+1] = mem[i+1][j];
                }
            }
        }
        
        return mem[t.length()][s.length()];        
    }
};
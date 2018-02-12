class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.empty()) return false;
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++) {
            for(int j = i-1; j >= 0; j--) {
                string word = s.substr(j, i-j);
                if(dp[j]) {
                    vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), word);
                    if (it != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.size()];      
    }
};
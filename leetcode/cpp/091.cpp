/*
 * DP
 *
 */

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int first = s[i-1]-'0';
            int second = (s[i-2]-'0')*10+(s[i-1]-'0');
            if(first >= 1 && first <= 9) dp[i] += dp[i-1];
            if(second >= 10 && second <= 26) dp[i] += dp[i-2];
        }
        return dp[n];        
    }
};

/*****


*****/





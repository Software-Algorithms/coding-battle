class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "") return s == "";
        
        // no '*'
        if(p[1] != '*') { // string beyond index still can be visited leagally, no worry
            if(s[0] == p[0] || (s[0] != '\0' && p[0] == '.')) {
                return isMatch(s.substr(1), p.substr(1));
            }
            return false;
        }
        
        // '*'
        int i = 0, j = 0;
        while(s[i] == p[j] || (s[i] != '\0' && p[j] == '.')) {
            if(isMatch(s.substr(i), p.substr(j+2))) return true;
            i++;
        }
        return isMatch(s.substr(i), p.substr(j+2));
    }
};
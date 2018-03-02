/**
 * DP
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "") return s == "";
        
        // cases are between p[1] is '*' or not
        if(p[1] != '*') { // string beyond index still can be visited legally, no worry
            if(s[0] == p[0] || (s[0] != '\0' && p[0] == '.')) {
                return isMatch(s.substr(1), p.substr(1));
            }
            return false;
        } else {
            // '*'
            int i = 0; // i represents the number of chars that p[0] matches
            while(s[i] == p[0] || (s[i] != '\0' && p[0] == '.')) {
                if(isMatch(s.substr(i), p.substr(2))) return true;
                i++;
            }
            return isMatch(s.substr(i), p.substr(2));
        }
    }
};
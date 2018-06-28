/*
 * Stack, DFS
 *
 */
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }
    
    string dfs(string& s, int& i) {
        string ret = "";
        while(i < s.size() && s[i] != ']') {
            if(!isdigit(s[i])) {
                ret += s[i++];
            } else {
                int n = 0;
                while(i < s.size() && isdigit(s[i])) {
                    n = n*10 + s[i++] - '0';
                }
                ++i; //'['
                string sub = helper(s, i);
                ++i;
                while(n--) {
                    ret += sub;
                }
            }
        }
        return ret;        
    }
};

// Conclusion:
//





/*
 * Hash Table
 */

// version 1:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        int len = s.length();
        unordered_map<char, int> codedS, codedT; // char --> last appeared index
        
        if(len == 0) return true;
        
        for(int i = 0; i < len; i++) {
            char sc = s[i], tc = t[i];
            if(codedS[sc] != codedT[tc]) return false;
            codedS[sc] = i+1;
            codedT[tc] = i+1;
        }
        
        return true;
    }
};

// version 2:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map_s[128] = {0};
        char map_t[128] = {0};
        int len = s.size();
        for (int i = 0; i < len; ++i) {
            if (map_s[s[i]] != map_t[t[i]]) return false;
            map_s[s[i]] = i+1;
            map_t[t[i]] = i+1;
        }
        return true;
    }
};

// Conclusion:
// in "map_s[s[i]] = i+1;", i+1 is used as a label.





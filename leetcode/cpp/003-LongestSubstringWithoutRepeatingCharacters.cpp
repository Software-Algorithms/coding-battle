/*
 * Two Pointers
 *
 */

// version 1:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int start = 0;
        int res = 0;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            int temp = 0;
            if(hash.find(c) != hash.end()) {
                temp = hash[c] + 1;
            }
            start = max(start, temp);
            res = max(res, i - start + 1);
            hash[c] = i;
        }
        return res;
    }
};

// version 2:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int i = 0, j = 0;
        
        unordered_map<char, int> m;
        
        while(i <= j && j < s.size()) {
            if(!m.count(s[j])) {
                m[s[j++]] = 1;
            } else {
                m.erase(s[i++]);
            }
            max_len = max(max_len, j-i);
        }
        
        return max_len;
    }
};

// Conclusion:
//




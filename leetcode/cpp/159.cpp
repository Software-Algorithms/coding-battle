/*
 * Two Pointers (Sliding Window), Hash Table
 *
 */

// version 1: recommended version
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0;
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); ++i) {
            ++hash[s[i]];
            while (hash.size() > 2) {
                if (--hash[s[left]] == 0) hash.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;        
    }
};

// version 2:
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> m;
        int n = s.size();
        int end = 0, max_len = 0;
        for(int i = 0; i < n; i++) {
            while(end < n && m.size() <= 2) {
                m[s[end]]++;
                end++;
            }
            if(m.size() == 3) {
                end--;
                m.erase(s[end]);
            }
            max_len = max(max_len, end - i);
            m[s[i]]--;
            if(m[s[i]] == 0) m.erase(s[i]);
        }
        return max_len;
    }
};

// Conlusion:
// 
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/5185561.html
//            http://www.cnblogs.com/grandyang/p/5351347.html




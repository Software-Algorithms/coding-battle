/*
 * Two Pointers (Sliding Window), Hash Table, String
 *
 */
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > k) {
                if (m[s[left]] == left) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;        
    }
};

// Conlusion:
// 
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/5185561.html
//            http://www.cnblogs.com/grandyang/p/5351347.html




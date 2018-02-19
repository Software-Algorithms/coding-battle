/*
 * Hash Table
 *
 */
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
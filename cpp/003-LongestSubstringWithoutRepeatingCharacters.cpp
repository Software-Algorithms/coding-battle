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
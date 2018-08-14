/*
 * string
 *
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string pre = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            while(strs[i].find(pre) != 0) {
                pre.pop_back();
            }
        }
        return pre;
    }
};


/*****
Take-away:
size_t find (const string& str, size_t pos = 0) const;
*****/


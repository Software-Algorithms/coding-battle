/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    String
 *
 * Idea:
 *    Pick the first word as a base to match each word's prefix. Remove the last
 *    character if unmatch and loop again.
 *
 * Complexity:
 *    Time: O(n)
 *
 * Take-away:
 *    size_t find (const string& str, size_t pos = 0) const;
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

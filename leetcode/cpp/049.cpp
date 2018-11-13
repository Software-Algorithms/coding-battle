/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array, Hash Table
 *
 * Idea:
 *    - Hash Table
 *
 * Complexity:
 *    Time: O(?)
 *
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;

        for (string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(s);
        }

        for(auto key : hash) {
            res.push_back(key.second);
        }
        return res;
    }
};


/**
 * Code description
 *
 * Author: xpharry
 * Date: ?
 *
 * Data structure:
 *    Array, Hash Table
 *
 * Idea:
 *    - Union Find
 *
 * Complexity:
 *    Time: O(?)
 *
 */

/*
 * Hash Table
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

/*****
Conclusion:

*****/


/*
 * DP + Backtracking
 *
 */
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(memo.count(s)) return memo[s];
        
        vector<string> res;
        
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) {
            res.push_back(s);
        }
        
        for(int i = 1; i < s.size(); i++) {
            string left = s.substr(0, i);
            if(find(wordDict.begin(), wordDict.end(), left) != wordDict.end()) {
                string right = s.substr(i);
                vector<string> list = concatenate(left, wordBreak(right, wordDict));
                res.insert(res.end(), list.begin(), list.end());
            }
        }
        
        memo[s] = res;
        return res;
    }
    
private:
    unordered_map<string, vector<string>> memo;
    
    vector<string> concatenate(string word, vector<string> strs) {
        for(int i = 0; i < strs.size(); i++) {
            strs[i] = word + " " + strs[i];
        }
        return strs;
    }
};

// Conclusion:
//
// search in a vector:
// pos = find(arr.begin(), arr.end(), entry); // return type is "size_t" which can be converted to "int"
//
// concatenate two vectors:
// arr1.insert(arr1.end(), arr2.begin(), arr2.end())




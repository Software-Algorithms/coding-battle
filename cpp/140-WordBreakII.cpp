class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(memo.count(s)) return memo[s]; //take from memory
        
        vector<string> result;
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) { //a whole string is a word
            result.push_back(s);
        }
        for(int i = 1; i < s.size(); ++i) {
            string left = s.substr(0, i);
            if(find(wordDict.begin(), wordDict.end(), left) != wordDict.end()) {
                string right = s.substr(i);
                vector<string> combined = combine(left, wordBreak(right, wordDict));
                result.insert(result.end(), combined.begin(), combined.end());
            }
        }
        memo[s] = result; //memorize
        return result;        
    }
    
private:
    unordered_map<string, vector<string>> memo;

    vector<string> combine(string word, vector<string> list) {
        for(int i = 0; i < list.size(); ++i) {
            list[i] = word + " " + list[i];
        }
        return list;
    }
};
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.size() <= 0) return ret;
        const string strs[] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrackingFunc(strs, digits, "", ret);
        return ret;
    }
    
    void backtrackingFunc(const string strs[], const string& digits, string cur, vector<string>& ret) {
        if(cur.size() == digits.size()) {
            ret.push_back(cur);
            return;
        }
        int idx = cur.size(); // next digit index
        string str = strs[digits[idx]-'0'];
        for(int i = 0; i < str.size(); i++) {
            cur.push_back(str[i]);
            backtrackingFunc(strs, digits, cur, ret);
            cur.pop_back();
        }
    }
};
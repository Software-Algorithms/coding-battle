/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Hash Table
 *
 * Idea:
 *    - Backtracking
 *
 * Complexity:
 *    Time: O(?)
 *
 * Take-away:
 *    1. Backtracking template
 *    2. backtracking()的第一个输入参数是字符串数组，不可以用reference，因为array of
 *       reference是非法的，会报错。
 *       > cite the C++ Standard §8.3.2/4:
 *       > There shall be no references to references, no arrays of references,
 *         and no pointers to references.
 *
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> res;
        const string strs[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(strs, digits, "", res);
        return res;
    }

    void backtracking(const string strs[], string& digits, string cur, vector<string>& res) {
        if(cur.size() == digits.size()) {
            res.push_back(cur);
            return;
        }

        int idx = cur.size();
        int digit = digits[idx] - '0';
        string button = strs[digit];
        for(int i = 0; i < button.size(); i++) {
            cur += button[i];
            backtracking(strs, digits, cur, res);
            cur.pop_back();
        }
    }
};

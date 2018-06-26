/*
 * String, Two Pointers
 *
 */
// version 1:
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(string str : d) {
            if(str.size() > s.size()) continue;
            int i = 0, j = 0;
            while(i < str.size() && j < s.size()) {
                if(str[i] == s[j]) i++;
                j++;
            }
            if(i == str.size()) {
                if(str.size() > res.size()) res = str;
                if(str.size() == res.size() && str < res) res = str;
            }
        }
        return res;
    }
};

// version 2:
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res = "";
        for(string str : d) {
            int i = 0;
            for(char c : s) {
                if(i < str.size() && str[i] == c) i++;
            }
            if(i == str.size() && str.size() >= res.size()) {
                if(str.size() > res.size() || str < res) res = str;
            }
        }
        return res;
    }
};

// Conclusion:
// Compare the string s and string picked from dictionary using Two Pointers.
//


/*
 * String, Two Pointers, Sort
 *
 */
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](string a, string b){
            if (a.size() == b.size()) return a < b;
            return a.size() > b.size();
        });
        for (string str : d) {
            int i = 0;
            for (char c : s) {
                if (i < str.size() && c == str[i]) ++i;
            }
            if (i == str.size()) return str;
        }
        return "";
    }
};

// Conclusion:
// After sorting, we don't need to travese the dictionary to the end. The first one that matches
// s would be the answer.


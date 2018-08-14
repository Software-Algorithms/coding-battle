/*
 * String
 *
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0, n = s.size();
        int start = 0, maxlen = 0;
        while(i < n) {
            int j = i, k = i;
            if(s.size()-i < maxlen/2) break;
            while(k < n-1 && s[k] == s[k+1]) k++;
            i = k + 1;
            while(j > 0 && k < n-1 && s[j-1] == s[k+1]) {
                j--;
                k++;
            }
            int newlen = k - j + 1;
            if(newlen > maxlen) {
                maxlen = newlen;
                start = j;
            }
        }
        return s.substr(start, maxlen);        
    }
};


/*****
注意可以运用剪枝除去不必要运算。
*****/


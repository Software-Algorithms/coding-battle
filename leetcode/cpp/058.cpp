class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, i = s.length()-1;
         //ignore the trailing whitespace
         for (; i >= 0 && s[i] == ' '; i--);
         for (; i >= 0 && s[i] != ' '; i--) len++;
         return len;
    }
};
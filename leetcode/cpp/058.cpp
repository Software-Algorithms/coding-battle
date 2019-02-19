/**
 * Code description
 *
 * Author: xpharry
 * Date: 12/3/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Backtracking.
 *
 * Complexity:
 *    Time: T(n) = n*T(n-1) + O(n^2) ~ O(n!)
 *    Space: O(n)
 *
 * Take-away:
 *    - string initialization: string = str(n, '.') which is similar to vector
 *
 */

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

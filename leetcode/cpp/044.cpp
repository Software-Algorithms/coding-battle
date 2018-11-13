/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/12/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - DP.
 *
 * Complexity:
 *    Time: O(?)
 *
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};


/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/12/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Two Pointers.
 *      - 'star' for the last position of '*' in 'p';
 *      - 'match' for the position to compare.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        int i = 0, j = 0;
        int star = -1, match = 0;
        while(i < n1) {
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length
            if( (s[i] == p[j]) || (p[j] == '?') ) {
                i++;
                j++;
                continue;
            }
            // * found in pattern, track last index of *, only advancing pattern pointer
            if(p[j] == '*') {
                star = j++;
                match = i; //? // the position in s where last star match until
                continue;
            }
            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing source pointer
            if(star != -1) {
                match++;
                i = match;
                // i++;
                j = star + 1;
                continue;
            }

            return false;
        }

        //check for remaining characters in pattern
        while(p[j] == '*') j++;

        return j >= n2;
    }
};

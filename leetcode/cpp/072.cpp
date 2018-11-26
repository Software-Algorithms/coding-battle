/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - DP.
 *    - DP Equation:
 *      dp[i][j] = dp[i - 1][j - 1], if word1[i - 1] == word2[j - 1]
 *         else:   min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1
 *
 * Reference:
 *    - http://www.cnblogs.com/grandyang/p/4344107.html
 *
 * Complexity:
 *    Time: O(n^2)
 *
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // initialize boarder
        for(int i = 0; i < m+1; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j < n+1; j++) {
            dp[0][j] = j;
        }

        // dp equation:
        // if(char compare equal) dp[i][j] = dp[i-1][j-1]
        // else dp[i][j] is least in (left, top, left top) +1
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1])) + 1;
            }
        }

        return dp[m][n];
    }
};

// Nov 25, 2018.
// Almost bugfree with the time limit.
// Missed one case in transition function.
class Solution {
public:
    int minDistance(string word1, string word2) {
        /*****
        Example: word1: abc, word2: abbc
               \0 a b b c
            \0  0 1 2 3 4
             a  1 0 1 2 3
             b  2 1 0 1 2
             c  3 2 1 1 1

        DP:
            state:
                dp[i][j] word1[0-i] --> word2[0-j]
            initialization:
                1st row: dp[0][j] = j;
                1st col: dp[i][0] = i;
            transition:
                case: word1[i-1] == word2[j-1] ==> dp[i][j] = dp[i-1][j-1]
                case: word1[i-1] != word2[j-1] ==> dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + 1  <== missing dp[i-1][j-1]
                                                                    delete      insert                       replace
            result:
                dp[m][n]
        *****/
        int m = word1.size(), n = word2.size();

        // state
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // initialization
        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        // transition
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                }
            }
        }

        return dp[m][n];
    }
};

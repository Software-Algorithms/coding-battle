/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    String
 *
 * Idea:
 *    - Devide and conquer.
 *    - Recursion.
 *    - 不用递归的话，还可以用DP的方法。参考 cnblogs.com/grandyang。
 *
 * Issue:
 *    - 需要注意到'.'还有对应无字符的情况；
 *    - 后一位字符为'*'的情况，每比较当前s中的一位，检查当前是否可以match，同时向后移位；
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p == "") return s == "";

        // cases are between p[1] is '*' or not
        if(p[1] != '*') { // string beyond index still can be visited legally, no worry
            if(s[0] == p[0] || (s[0] != '\0' && p[0] == '.')) {
                return isMatch(s.substr(1), p.substr(1));
            }
            return false;
        } else {
            // '*'
            int i = 0; // i represents the number of chars that p[0] matches
            while(s[i] == p[0] || (s[i] != '\0' && p[0] == '.')) {
                if(isMatch(s.substr(i), p.substr(2))) return true;
                i++;
            }
            return isMatch(s.substr(i), p.substr(2));
        }
    }
};


/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/18/2018
 *
 * Data structure:
 *    String
 *
 * Idea:
 *    - DP.
 *    - 参考 cnblogs.com/grandyang。
 *    - Example: abcd <==> a*.cd
 *                    p 0 1 2 3 4 5
 *                 s
 *                 0    T T F F F F
 *                 1    F T T F F F
 *                 2    F F F T F F
 *                 3    F F F F T F
 *                 4    F F F F F T
 *    - 1) State: dp[i][j] represents if s[0..i) matches p[0..j)
 *      2) Transition function:
 *         a.  P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] ==
 *             p[j - 1] || p[j - 1] == '.');
 *         b.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats
 *             for 0 times;
 *         c.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'),
 *             if p[j - 1] == '*' and the pattern repeats for at least 1 times.
 *       3) Initialization:
 *          dp[0][0] = true;
 *       4) Result:
 *          dp[m][n]
 *
 * Complexity:
 *    Time: O(n)
 *
 */
 class Solution {
 public:
     bool isMatch(string s, string p) {
         int m = s.size(), n = p.size();
         vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
         dp[0][0] = true;
         for (int i = 0; i <= m; ++i) {
             for (int j = 1; j <= n; ++j) {
                 if (j > 1 && p[j - 1] == '*') {
                     dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                 } else {
                     dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
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
 * Date: 11/18/2018
 *
 * Data structure:
 *    String
 *
 * Idea:
 *    - DP.
 *    - 参考 LeetCode Discuss。
 *      1, If p.charAt(j) == s.charAt(i) :  dp[i][j] = dp[i-1][j-1];
 *      2, If p.charAt(j) == '.' : dp[i][j] = dp[i-1][j-1];
 *      3, If p.charAt(j) == '*':
 *         here are two sub conditions:
 *               1   if p.charAt(j-1) != s.charAt(i) : dp[i][j] = dp[i][j-2]  //in this case, a* only counts as empty
 *               2   if p.charAt(i-1) == s.charAt(i) or p.charAt(i-1) == '.':
 *                              dp[i][j] = dp[i-1][j]    //in this case, a* counts as multiple a
 *                           or dp[i][j] = dp[i][j-1]   // in this case, a* counts as single a
 *                           or dp[i][j] = dp[i][j-2]   // in this case, a* counts as empty
 */
 class Solution {
 public:
     bool isMatch(string s, string p) {
         int m = s.size(), n = p.size();
         vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
         dp[0][0] = true;
         for (int i = 0; i < n; i++) {
             if (p[i] == '*' && dp[0][i-1]) {
                 dp[0][i+1] = true;
             }
         }
         for (int i = 0 ; i < m; i++) {
             for (int j = 0; j < n; j++) {
                 if (s[i] == p[j] || p[j] == '.') {
                     dp[i+1][j+1] = dp[i][j];
                 }
                 if (p[j] == '*') {
                     if (s[i] != p[j-1] && p[j-1] != '.') {
                         dp[i+1][j+1] = dp[i+1][j-1];
                     } else {
                         dp[i+1][j+1] = (dp[i+1][j] || dp[i][j+1] || dp[i+1][j-1]);
                     }
                 }
             }
         }
         return dp[m][n];
     }
 };

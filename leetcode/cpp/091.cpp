/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array, Stack
 *
 * Idea:
 *    - DP.
 *    - version 1
 *    - 每次看两位:
 *        a) 当前位大于0（后者说：>=1 && <= 9），当前位可以单独被decode;
 *        b) 当前位和前一位组成的数是否处于10-26的范围内，是的话，该两位可以被decode。
 *
 * Complexity:
 *    O()
 *
 */
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            int first = s[i-1]-'0';
            int second = (s[i-2]-'0')*10+(s[i-1]-'0');
            if(first >= 1 && first <= 9) dp[i] += dp[i-1];
            if(second >= 10 && second <= 26) dp[i] += dp[i-2];
        }
        return dp[n];
    }
};

/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array, Stack
 *
 * Idea:
 *    - DP.
 *    - version 2: Geeksforgeeks
 *    - 基本思路与version 1一致，执行稍有区别，品味下两种风格。
 *
 * Complexity:
 *    O()
 *
 */
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;

        int n = s.size();
        int count[n+1]; // A table to store results of subproblems
        count[0] = 1;
        count[1] = 1;

        for (int i = 2; i <= n; i++) {
            count[i] = 0;

            // If the last digit is not 0, then last digit must add to
            // the number of words
            if (s[i-1] > '0')
                count[i] = count[i-1];

            // If second last digit is smaller than 2 and last digit is
            // smaller than 7, then last two digits form a valid character
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] < '7') )
                count[i] += count[i-2];
        }
        return count[n];
    }
};

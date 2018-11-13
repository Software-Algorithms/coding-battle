/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/10/2018
 *
 * Data structure:
 *    String
 *
 * Idea:
 *    - Math.
 *    - Deal with prefix spaces;
 *    - Reserve the sign;
 *    - Convert each digit;
 *    - Check the overflow problem.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        int i = 0;
        while(str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-') {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9') {
            if(res > INT_MAX/10 || (res == INT_MAX/10 && str[i] > '7') ) {
                if(sign == 1) return INT_MAX;
                return INT_MIN;
            }
            res = res*10 + (str[i] - '0');
            i++;
        }
        return res*sign;
    }
};

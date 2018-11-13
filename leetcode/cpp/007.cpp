/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/10/2018
 *
 * Data structure:
 *
 * Idea:
 *    - Math.
 *    - Reserve the sign and operate the digits.
 *    - The only take-way from this problem is to be careful with the overflow
 *      problem. And one way to check if overflow happens is like check if
 *      "num * 10 / 10 == num" can be established.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    int reverse(int x) {
        int y = abs(x);
        int res = 0;
        while(y) {
            if(res*10/10 != res) // avoid overflow before *10
                return 0;
            res = res*10 + y%10;
            y /= 10;
        }
        if(x<0) res = -res;
        return res;
    }
};

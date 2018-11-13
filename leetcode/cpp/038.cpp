/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    String, Array
 *
 * Idea:
 *    - DP
 *    - 可以用recursion，也可以直接iteration。下次实现下后者。
 *    - 参考（Reference）:
 *      http://bangbingsyb.blogspot.com/2014/11/leetcode-count-and-say.html
 *
 * Complexity:
 *    Time: O(?)
 *
 */
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string str = countAndSay(n-1);
        char c = str[0];
        int count = 0;
        string res = "";
        for(int i = 0; i < str.length(); i++) {
            if(c == str[i]) count++;
            else {
                res += to_string(count) + c;
                c = str[i];
                count = 1;
            }
            if(i == str.length()-1)
                res += to_string(count) + str[i];
        }
        return res;
    }
};

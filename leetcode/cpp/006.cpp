/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/10/2018
 *
 * Data structure:
 *    String, Array
 *
 * Idea:
 *    - I don't know how to put it into some known algorithm.
 *    - Use two variables, 'row' and 'step', to control character loading.
 *    - As in the example,
 *      P   A   H   N
 *      A P L S I I G
 *      Y   I   R
 *      it seems to convay that 'P', 'A', 'Y' are in the same column while the
 *      2nd column contains only 'P' and other ' ' charaters, which is confusing
 *      at the first sight.
 *      Acutually, only the direction here matters. We can show it in other way,
 *      P   A   H   N
 *       A P L S I I G
 *        Y   I   R
 *    - Seems that it used to be an easy one. No need to waste too much time.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;

        vector<string> strs(numRows);

        int row = 0;
        int step = 1;
        for(int i = 0; i < s.length(); i++) {
            strs[row].push_back(s[i]);
            if(row == 0) {
                step = 1;
            } else if(row == numRows-1) {
                step = -1;
            }
            row += step;
        }

        string res = "";
        for(int i = 0; i < numRows; i++) {
            res += strs[i];
        }

        return res;
    }
};

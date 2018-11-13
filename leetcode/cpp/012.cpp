/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Hash Table
 *
 * Idea:
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strs[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string toRoman = "";
        for(int i = 0; i < 13; i++) {
            while(num >= values[i]) {
                num -= values[i];
                toRoman += strs[i];
            }
        }
        return toRoman;
    }
};

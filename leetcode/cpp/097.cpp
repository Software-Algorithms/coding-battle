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
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;

        bool table[s1.length()+1][s2.length()+1];

        for(int i=0; i<s1.length()+1; i++)
            for(int j=0; j< s2.length()+1; j++){
                if(i==0 && j==0)
                    table[i][j] = true;
                else if(i == 0)
                    table[i][j] = ( table[i][j-1] && s2[j-1] == s3[i+j-1]);
                else if(j == 0)
                    table[i][j] = ( table[i-1][j] && s1[i-1] == s3[i+j-1]);
                else
                    table[i][j] = (table[i-1][j] && s1[i-1] == s3[i+j-1] ) || (table[i][j-1] && s2[j-1] == s3[i+j-1] );
            }

        return table[s1.length()][s2.length()];
    }
};

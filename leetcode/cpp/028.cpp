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
 *    - Two Pointers.
 *
 * Complexity:
 *    Time: O(n)
 *
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = 0;
        if(0 == needle.size()) return 0;

        // check uniformity
        while(i<(int)(haystack.size()-needle.size()+1)) {
            while(j<needle.size() && haystack[i+j] == needle[j]) j++;
            if(j == needle.size()) return i;
            j = 0;
            i++;
        }

        return -1;
    }
};

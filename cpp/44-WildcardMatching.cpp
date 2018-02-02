class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.length(), n2 = p.length();
        int i = 0, j = 0;
        int star = -1, match = 0;
        while(i < n1) {
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length
            if( (s[i] == p[j]) || (p[j] == '?') ) {
                i++;
                j++;
                continue;
            }
            // * found in pattern, track last index of *, only advancing pattern pointer
            if(p[j] == '*') {
                star = j++;
                match = i; //? // the position in s where last star match until
                continue;
            }
            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing source pointer
            if(star != -1) {
                match++;
                i = match;
                // i++;
                j = star + 1;
                continue;
            }
            
            return false;
        }
        
        //check for remaining characters in pattern
        while(p[j] == '*') j++;
        
        return j >= n2;
    }
};
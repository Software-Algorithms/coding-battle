/*
 * String
 *
 */
class Solution {
public:
    bool checkRecord(string s) {
        int cntA = 0; //count 'A'
        if(s.find("LLL", 0) != string::npos){ // no more than two continuous 'A'
            return false;
        }
        for(auto c : s){// count 'A'
            if(c == 'A') cntA++;
            if(cntA > 1) {
                return false;
            }
        }
        return true;        
    }
};

// Conclusion:
// Nothing difficult, just be careful when understanding the problem description.






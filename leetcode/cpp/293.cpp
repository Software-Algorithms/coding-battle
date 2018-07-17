/*
 * String
 *
 */
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        // traverse from 0 to s.size()-2
        // check each concecutive pairs, if possible for "++" to "--"
        // record/push_back into the string vector 
        vector<string> moves;
        int n = s.length();
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') { 
                s[i] = s[i + 1] = '-';
                moves.push_back(s);
                s[i] = s[i + 1] = '+'; // need to restore s for the subsequent move cases
            }
        }
        return moves;        
    }
};

// Conclusion:
//





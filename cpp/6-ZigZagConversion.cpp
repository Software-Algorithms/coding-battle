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
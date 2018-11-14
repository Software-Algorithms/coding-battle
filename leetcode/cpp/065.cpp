class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        // pre-process
        while(s[i] == ' ') i++;
        if(s[i] == '+' || s[i] == '-') i++;
        
        // main process
        int nNum = 0, nPoint = 0;
        while( (s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
            if(s[i] == '.') nPoint++;
            else nNum++;
            i++;
        }
        if(nPoint > 1 || nNum < 1) return false;
        
        // consider 'e'
        if(s[i] == 'e') {
            i++;
            if(s[i] == '+' || s[i] == '-') i++;
            nNum = 0;
            while(s[i] >= '0' && s[i] <= '9') {
                nNum++;
                i++;
            }
            if(nNum < 1) return false;
        }
        
        // post-process
        while(s[i] == ' ') i++;
        
        return s[i] == 0;
    }
};
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(s, "", res, 0);
        return res;
    }
    
    void helper(string s, string tmp, vector<string>& res, int n){
        if(n == 4){
            if(s.length() == 0) res.push_back(tmp.substr(0,tmp.length()-1));
            //substring here to get rid of last '.'
            return;
        }
        for(int k = 1; k <= 3; k++) {
            if(s.length() < k) break; // 无法组成数字段
            int val = stoi(s.substr(0,k));
            if(val > 255 || k != to_string(val).length()) continue;
            /*in the case 010 the parseInt will return len=2 where val=10, but k=3, skip this.*/
            helper(s.substr(k), tmp+s.substr(0,k)+".", res, n+1);
        }        
    }
};
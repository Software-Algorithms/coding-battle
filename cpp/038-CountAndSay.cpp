class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string str = countAndSay(n-1);
        char c = str[0];
        int count = 0;
        string res = "";
        for(int i = 0; i < str.length(); i++) {
            if(c == str[i]) count++;
            else {
                res += to_string(count) + c;
                c = str[i];
                count = 1;
            }
            if(i == str.length()-1)
                res += to_string(count) + str[i];
        }
        return res;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        
        while(i >= 0 || j >= 0 || carry) {
            int tmp = 0;
            tmp += carry;
            if(i>=0) tmp += a[i--] - '0';
            if(j>=0) tmp += b[j--] - '0';
            carry = tmp/2;
            tmp = tmp%2;
            s = to_string(tmp) + s;
        }
        return s;
    }
};
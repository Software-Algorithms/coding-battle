class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.size() + num2.size(), '0');
        
        for (int i = num1.size() - 1; 0 <= i; --i) {
            int carry = 0;
            for (int j = num2.size() - 1; 0 <= j; --j) {
                int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry; // i+j+1 make it starts from the last digit of sum
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
        
        int i = 0;
        while(sum[i] == '0') i++;
        if(i >= sum.size()) return "0";
        return sum.substr(i);        
    }
};
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1, n = digits.size();
        vector<int> newdigits(n);
        for(int i = n-1; i >= 0; i--) {
            int temp = digits[i] + carry;
            carry = temp/10;
            newdigits[i] = temp%10;
        }
        if(carry)
            newdigits.insert(newdigits.begin(), carry);
        return newdigits;
    }
};
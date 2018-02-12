class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32); // Construct a 32 bit array.

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < 32; j++) { // from low to high
                if (!(nums[i] >> j)) break;
                bit[j] += (nums[i] >> j) & 1; // Find the last digit.
            }
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++) { // from lower digit to higher digit
            res += (bit[i]%3 << i); // recover the target number
        }
        
        return res;        
    }
};
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //xor all numbers, the left over number would be the non repeated one
        // since the equl numbers cancel out each others bits
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num ^= nums[i];
        }
        return num;        
    }
};
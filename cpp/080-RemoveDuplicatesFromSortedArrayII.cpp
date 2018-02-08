class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // two pointers here are count and num respectively
        int i = 0;
        for(int num : nums) {
            if(i < 2 || num > nums[i-2]) {
                nums[i++] = num;
            }
        }
        return i;
    }
};
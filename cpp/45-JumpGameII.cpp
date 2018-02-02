class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, cur = 0, i = 0;
        while(cur < n-1) {
            int pre = cur;
            while(i <= pre) {
                cur = max(cur, i + nums[i]);
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};
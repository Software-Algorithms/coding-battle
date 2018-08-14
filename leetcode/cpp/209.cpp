/*
 * Two Pointers / Sliding Window
 * 
 */

// version 1: start and i (as end)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};

// version 2: i (as start) and end
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int end = 0, n = nums.size();
        int sum = 0, min_len = INT_MAX;
        for(int i = 0; i < n; i++) {
            while(end < n && sum < s) {
                sum += nums[end];
                end++;
            }
            if(sum >= s) {
                min_len = min(min_len, end - i);
            }
            sum -= nums[i];
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

/*****
Conclusion:
套路题： Sliding Window.
*****/





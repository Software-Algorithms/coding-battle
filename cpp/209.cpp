/*
 * Two Pointers
 * 
 */

// version 1: i as end, start as start
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

// version 2: i as start, j as end
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {    
        int i = 0, j = 0;
        int sum = 0, min_len = INT_MAX;
        for(; i < nums.size(); i++) {
            while(j < nums.size() && sum < s) {
                sum += nums[j];
                j++;
            }
            if(sum >= s) min_len = min(min_len, j - i);
            sum -= nums[i];
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

// Conclusion:
// Can use a generic template to solve this kind of problems.
//




/*
 * DP
 *
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0], maxEndingHere = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            maxEndingHere = max(maxEndingHere+nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};

/*****
小结（Conclusion）:
经典的Kadane’s Algorithm

要点（Take-away）：
Kadane’s Algorithm:
···
Initialize:
    max_so_far = 0
    max_ending_here = 0

Loop for each element of the array
  (a) max_ending_here = max_ending_here + a[i]
  (b) if(max_ending_here < 0)
            max_ending_here = 0
  (c) if(max_so_far < max_ending_here)
            max_so_far = max_ending_here
return max_so_far
···

参考（Reference）:
Geekforgeeks - Largest Sum Contiguous Subarray: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
Maximum Subarray Problem (Kadane's algorithm): http://www.techiedelight.com/maximum-subarray-problem-kadanes-algorithm/
*****/


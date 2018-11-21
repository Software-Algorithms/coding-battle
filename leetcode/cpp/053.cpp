/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Kadane’s Algorithm:
 *    ···
 *      Initialize:
 *        max_so_far = 0
 *        max_ending_here = 0
 *      Loop for each element of the array
 *        (a) max_ending_here = max_ending_here + a[i]
 *        (b) if(max_ending_here < 0)
 *                max_ending_here = 0
 *        (c) if(max_so_far < max_ending_here)
 *                max_so_far = max_ending_here
 *      return max_so_far
 *    ...
 *
 * Complexity:
 *    Time: O(lgn)
 *
 * Reference:
 *    - Geekforgeeks - Largest Sum Contiguous Subarray:
 *      https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
 *    - Maximum Subarray Problem (Kadane's algorithm):
 *      http://www.techiedelight.com/maximum-subarray-problem-kadanes-algorithm/
 */
 class Solution {
 public:
     int maxSubArray(vector<int>& nums) {
         // the sub array has two cases:
         // one is ending with the current element
         // the other is not
         // we find a way to cover the both cases,
         // we will find the optimize solution or here the max value

         // we thus use two variable to record the max vulues
         // maxEndingHere: the max subarray sum value ending here
         // maxSoFar: the max subarray sum cosidering both

         if(nums.empty()) return 0;

         int maxEndingHere = nums[0], maxSoFar = nums[0];

         for(int i = 1; i < nums.size(); i++) {
             maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
             maxSoFar = max(maxSoFar, maxEndingHere);
         }

         return maxSoFar;
     }
 };

// 138. Subarray Sum
// https://www.lintcode.com/problem/subarray-sum/description
// https://www.jiuzhang.com/solutions/subarray-sum

/*
 * Array, Hash Table
 *
 */
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
        // write your code here
        int sum = 0;
        unordered_map<int, int> m; // sum --> index
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum == 0) return {0, i};
            if(m.count(sum)) return {i, m[sum]+1};
            m[sum] = i;
        }
        return {-1, -1};
    }
};

// Conclusion:
// Hash:
// val --> index is quite useful to check repeat





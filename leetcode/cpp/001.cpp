/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/10/2018
 *
 * Data structure:
 *    Array, Hash Table
 *
 * Idea:
 *    - Brute Force search is in O(n^2)
 *    - Hash Map allows O(1) search which lowers the complexity to O(n)
 *
 * Complexity:
 *    Time: O()
 *
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            if(hash.count(target - nums[i])) {
                return {hash[target-nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};

/**
 * Code description
 *
 * Author: xpharry
 * Date: 12/3/2018
 *
 * Data structure:
 *    Array
 *
 * Issue:
 *    line10 and line11的顺序让我一开始稍微弄混了。
 *
 * Idea:
 *    - Backtracking.
 *
 * Complexity:
 *    Time: T(n) = n*T(n-1) + O(n^2) ~ O(n!)
 *    Space: O(n)
 *
 * Take-away:
 *
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(max_reach < i) return false;
            max_reach = max(max_reach, i + nums[i]);
        }
        return true;
    }
};

/*
 * Array, DP
 *
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> unvisited(nums.begin(), nums.end());
        
        int max_len = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            if(unvisited.empty()) break;
            
            int cur_len = 0, cur_num = nums[i];
            
            while(unvisited.count(cur_num)) {
                unvisited.erase(cur_num);
                cur_len++;
                cur_num++;
            }
            
            cur_num = nums[i] - 1;
            while(unvisited.count(cur_num)) {
                unvisited.erase(cur_num);
                cur_len++;
                cur_num--;
            }
            
            max_len = max(max_len, cur_len);
        }
        
        return max_len;
    }
};

/*****
Conclusion:

Reference:
Leetcode Discuss: https://leetcode.com/problems/longest-consecutive-sequence/discuss/140851/easy-to-understand-C++-beat-98.6-using-only-unordered_set
Grandyang: http://www.cnblogs.com/grandyang/p/4276225.html
*****/


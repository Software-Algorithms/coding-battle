/*
 * Array, DP (?)
 *
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int> ht(nums.begin(), nums.end());
            
        int maxLen = 1;
        for(int i=0; i<nums.size(); i++) {
            if(ht.empty()) break;
            int curLen = 0;
            int curNum = nums[i];
            
            while(ht.count(curNum)) {
                ht.erase(curNum);
                curLen++;
                curNum++;
            }
            
            curNum = nums[i]-1;
            while(ht.count(curNum)) {
                ht.erase(curNum);
                curLen++;
                curNum--;
            }
            
            maxLen = max(maxLen, curLen);
        }
        
        return maxLen;        
    }
};

// Conclusion:
//
// Reference:
// Leetcode Discuss: https://leetcode.com/problems/longest-consecutive-sequence/discuss/140851/easy-to-understand-C++-beat-98.6-using-only-unordered_set
// Grandyang: http://www.cnblogs.com/grandyang/p/4276225.html




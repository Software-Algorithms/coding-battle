/*
 * Hash Table
 *
 * O(n)
 *
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
    }
};


/*
 * Moore Voting Algorithm
 *
 * O(n)
 *
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(count == 0) {
                count++;
                maj = nums[i];
            } else if(maj == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        return maj;
    }
};


/*
 * Bit Manipulation (work?)
 *
 * O(n^2)
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
        } 
        return major;
    } 
};


/**
 * Reference
 *
 * https://leetcode.com/problems/majority-element/discuss/51612/6-Suggested-Solutions-in-C++-with-Explanations
 *
 */
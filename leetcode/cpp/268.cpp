/*
 * Array, Math
 *
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return n*(n+1)/2-sum;        
    }
};

// Conclusion:
// 最直观的一个方法是用等差数列的求和公式求出0到n之间所有的数字之和，然后
// 再遍历数组算出给定数字的累积和，然后做减法，差值就是丢失的那个数字。
//
// Similar Problems:
// 41, 765



/*
 * Bit Manipulation
 *
 */ 

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res ^= (i + 1) ^ nums[i];
        }
        return res;
    }
};

// Idea：
// 使用位操作Bit Manipulation来解的，用到了异或操作的特性，相似的题目有
// Single Number 单独的数字, Single Number II 单独的数字之二和Single
// Number III 单独的数字之三。那么思路是既然0到n之间少了一个数，我们将这
// 个少了一个数的数组合0到n之间完整的数组异或一下，那么相同的数字都变为0了，
// 剩下的就是少了的那个数字了。
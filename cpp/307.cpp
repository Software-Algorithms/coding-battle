/*
 * BIT (Binary Indexed Tree)
 *
 */
class NumArray {
public:
    NumArray(vector<int> nums) {
        num.resize(nums.size() + 1);
        bit.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - num[i + 1];
        for (int j = i + 1; j < num.size(); j += (j&-j)) {
            bit[j] += diff;
        }
        num[i + 1] = val;
    }
    
    int sumRange(int i, int j) {
        return getSum(j + 1) - getSum(i);
    }
    
    int getSum(int i) {
        int res = 0;
        for (int j = i; j > 0; j -= (j&-j)) {
            res += bit[j];
        }
        return res;
    }

private:
    vector<int> num;
    vector<int> bit;
};

// Conclusion:
//
//
// Binary Indexed Tree
// 树状数组或二叉索引树（英语：Binary Indexed Tree），又以其发明者命名为Fenwick树。
// 这是一种查询和修改复杂度均为O(logn)的数据结构。
//
// Reference:
// http://www.cnblogs.com/grandyang/p/4985506.html
// https://zh.wikipedia.org/wiki/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84




// Lintcode 507. Wiggle Sort II
// Problem description: https://lintcode.com/problem/wiggle-sort-ii/description
// Problem solution: https://jiuzhang.com/solutions/wiggle-sort-ii

/*
 * Solution 1:
 * Array, Sort
 *
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> tmp = nums;
        int n = nums.size(), k = (n + 1) / 2, j = n; 
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            nums[i] = i & 1 ? tmp[--j] : tmp[--k];
        }        
    }
};

// Conclusion:
// Time: O(nlgn)
// Eg: Sorted: 1 2 3 | 4 5 6
//     Output: 1 4 2 5 3 6




/*
 * Solution 2:
 * Array, Sort (Quick Sort / Partition Algorithm)
 *
 */

// version 1: self-defining a find-kth-element function using partition
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        int n = nums.size();        
        
        vector<int> tmp(nums);
        int mid = partition(tmp, 0, n-1, n/2);
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = mid;

        int l, r;
        if (n % 2 == 0) {
            l = n - 2;
            r = 1;
            for (int i = 0; i < n; i++) {
                if (nums[i] < mid) {
                    ans[l] = nums[i];
                    l -= 2;
                } else if (nums[i] > mid) {
                    ans[r] = nums[i];
                    r += 2;
                }
            }
        } else {
            l = 0;
            r = n - 2;
            for (int i = 0; i < n; i++) {
                if (nums[i] < mid) {
                    ans[l] = nums[i];
                    l += 2;
                } else if (nums[i] > mid) {
                    ans[r] = nums[i];
                    r -= 2;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }

private:
    int partition(vector<int>& nums, int l, int r, int rank) {
        int left = l, right = r;
        int now = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= now) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= now) {
                left++;
            }
            nums[right] = nums[left];
        }
        if (left - l == rank) {
            return now;
        } else if (left - l < rank) {
            return partition(nums, left + 1, r, rank - (left - l + 1));
        } else {
            return partition(nums, l, right - 1, rank);
        }
    }
};

// Conclusion:
// O(n)时间复杂度+O(1)空间复杂度解法：
// 1. 使用O(n)时间复杂度的quickSelect算法，从未经排序的数组nums中选出中位数mid
// 2. 参照解法I的思路，将nums数组的下标x通过函数idx()从[0, 1, 2, ... , n - 1, n] 映射到 [1, 3, 5, ... , 0, 2, 4, ...]，得到新下标ix
// 3. 以中位数mid为界，将大于mid的元素排列在ix的较小部分，而将小于mid的元素排列在ix的较大部分。
//
// Reference:
// https://leetcode.com/discuss/77133/o-n-o-1-after-median-virtual-indexing
//

// version 2: use a built-in find-kth-element function in cpp
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: nothing
     */
    void wiggleSort(vector<int> &nums) {
        // write your code here
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;

        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};

// Conclusion:
//
//
// Reference:
//
//





/*
 * Binary Search
 *
 */
class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (x <= 0) {
            return 0;
        }

        int start = 1;
        int end = x;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                end = mid;
            } else {
                start = mid;
            }
        }

        return start;
    }
};

// Conclusion:
// 有几点很strugglling:
// 1. 为什么循环条件是 start + 1 < end , 而不是通常的 start < end ?
// 2. 第三个条件下，为什么是 start = mid ，而不是 start = mid + 1 ?
//
//




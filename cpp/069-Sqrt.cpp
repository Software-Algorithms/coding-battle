/*
 * Binary Search
 *
 * Time: O(lgn)
 *
 */
class Solution {
public:
    int mySqrt(int x) {
        int l = 1, r = x;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(mid == x/mid) return mid;
            if(mid < x/mid) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l-1;
    }
};


/*
 * Newton's method
 *
 */
class Solution {
public:
    int mySqrt(int x) {
        long res = x;
        while(res * res > x) {
            res = (res + x / res) / 2; // Newton Method
        }
        return res;
     }
};
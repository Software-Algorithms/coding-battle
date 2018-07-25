/*
 * DP
 *
 */
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        int same = 0, diff = k, res = same + diff;
        for (int i = 2; i <= n; ++i) {
            same = diff;
            diff = res * (k - 1);
            res = same + diff;
        }
        return res;
    }
};

// Reference:
// Youtube by Geeksforgeeks: https://www.youtube.com/watch?v=FDYRfavMV8k






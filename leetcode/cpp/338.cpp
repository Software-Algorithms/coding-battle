/*
 * Solution 1: DP
 *
 */
class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        vector<int> res{0, 1};
        int k = 2, i = 2;
        while (i <= num) {
            for (i = pow(2, k - 1); i < pow(2, k); ++i) {
                if (i > num) break;
                int t = (pow(2, k) - pow(2, k - 1)) / 2;
                if (i < pow(2, k - 1) + t) res.push_back(res[i - t]);
                else res.push_back(res[i - t] + 1);
            }
            ++k;
        }
        return res;
    }
};

/*****
Reference:
Grandyang: http://www.cnblogs.com/grandyang/p/5294255.html 解法一
*****/


/*
 * Solution 2: DP
 *
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res{0};
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) res.push_back(res[i / 2]);
            else res.push_back(res[i / 2] + 1);
        }
        return res;
    }
};

/*****
Conclusion:
f[i] = f[i>>1] + (i mod 2)

Reference:
Grandyang: http://www.cnblogs.com/grandyang/p/5294255.html 解法二
九章动态规划班。
*****/




/*
 * Solution 3: DP
 *
 */
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for (int i = 1;  i <= num; i++) {
            res[i] = res[i & (i-1)] + 1;
        }
        return res;
    }
};

/*****
Reference:
Grandyang: http://www.cnblogs.com/grandyang/p/5294255.html 解法四
*****/





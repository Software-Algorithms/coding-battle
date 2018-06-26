/*
 * Bit Manipulation
 *
 * Time: O(n^2), Space: O(n)
 *
 * Mirror arrangement
 *
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1);
        for(int i = 0; i < n; i++) {
            int inc = 1 << i;
            int size = ret.size();
            for(int j = size-1; j >= 0; j--) {
                ret.push_back(ret[j] | inc);
            }
        }
        return ret;
    }
};


/*
 * Backtracking
 *
 * Time: O(), Space: O(n)
 *
 * Use a set to avoid duplicates.
 * 从0开始，遍历其二进制每一位，对其取反，然后看其是否在set中出现过，如果没有，我们将其加入set和结果res中，
 * 然后再对这个数的每一位进行遍历，以此类推就可以找出所有的格雷码
 *
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        unordered_set<int> s;
        helper(n, s, 0, res);
        return res;
    }

    void helper(int n, unordered_set<int>& s, int out, vector<int>& res) {
        s.insert(out);
        res.push_back(out);
        for (int i = 0; i < n; ++i) {
            int t = out;
            if ((t & (1 << i)) == 0) t |= (1 << i); // 0 -> 1
            else t &= ~(1 << i); // 1 -> 0
            if (s.count(t)) continue;
            helper(n, s, t, res);
        }
    }
};
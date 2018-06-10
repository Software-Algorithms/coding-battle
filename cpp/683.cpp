/*
 * BST
 *
 */
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        set<int> s;
        for (int i = 0; i < flowers.size(); ++i) {
            int cur = flowers[i];
            auto it = s.upper_bound(cur);
            if (it != s.end() && *it - cur == k + 1) {
                return i + 1;
            }
            it = s.lower_bound(cur);
            if (it != s.begin() && cur - *(--it) == k + 1) {
                return i + 1;
            }
            s.insert(cur);
        }
        return -1;
    }
};

// Reference:
// http://www.cnblogs.com/grandyang/p/8415880.html
// https://leetcode.com/problems/k-empty-slots/discuss/107948/Iterate-over-time-vs.-iterate-over-position




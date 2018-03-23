/*
 * Hash Table
 *
 * Ref: grandyang
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long long, int> m;
        int j = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - j > k) m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if (a != m.end() && abs(a->first - nums[i]) <= t) return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
/* -------

    map.lower_bound()

   ------- */


/**
 * BST
 *
 * Ref: leetcode discuss
 */
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k && i - k - 1 < nums.size()) window.erase(nums[i - k - 1]);
            auto it = window.lower_bound((long long)nums[i] - t);
            if (it != window.cend() && *it - nums[i] <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};
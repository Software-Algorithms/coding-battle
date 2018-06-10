/*
 * BST
 *
 */
// version 1:
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

// version 2:
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        if (n == 0 || k >= n) return -1;        
        set<int> xs;        
        for (int i = 0; i < n; ++i) {
            int x = flowers[i];
            auto r = xs.insert(x).first;
            auto l = r;
            if (++r != xs.end() && *r == x + k + 1) return i + 1;
            if (l != xs.begin() && *(--l) == x - k - 1) return i + 1;
        }
        
        return -1;
    }
};

// Conclusion:
// Observe from the time view, we tranverse the array "flowers" and by time we store each flower position in order.
// So we can refer to set container in cpp which is implemented as a Balanced Binary Tree. By set, we can easily 
// visit the prior and following value by lower_bound and upper_bound.
//
// Set in cpp:
// Sets are containers that store unique elements following a specific order. 
// Sets are typically implemented as binary search trees.
// std::set::upper_bound (>)  & std::set::lower_bound (>=)
//   - Returns an iterator pointing to the first element in the container which is considered to go after val.
//   - lower_bound, has the same behavior as upper_bound, except in the case that the set contains an element 
//     equivalent to val: In this case lower_bound returns an iterator pointing to that element, whereas upper_bound
//     returns an iterator pointing to the next element.
//
// Reference:
// http://www.cnblogs.com/grandyang/p/8415880.html
// https://leetcode.com/problems/k-empty-slots/discuss/107948/Iterate-over-time-vs.-iterate-over-position




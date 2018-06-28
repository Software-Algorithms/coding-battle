// 202. Segment Tree Query
// https://www.lintcode.com/problem/segment-tree-query/description
// https://www.jiuzhang.com/solutions/segment-tree-query#tag-highlight-lang-cpp

/*
 * Segment Tree
 *
 */

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of segment tree.
     * @param start: start value.
     * @param end: end value.
     * @return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode * root, int start, int end) {
        // write your code here
        if (root->end < start || root->start > end)
            return INT_MIN;
  
        if (root->start >= start && root->end <= end)
            return root->max;

        int l = query(root->left, start, end);
        int r = query(root->right, start, end);
        return l > r ? l : r;
    }
};

// Conclusion:
//





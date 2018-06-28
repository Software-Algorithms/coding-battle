// 247. Segment Tree Query II
// https://www.lintcode.com/problem/segment-tree-query-ii/description
// https://www.jiuzhang.com/solutions/segment-tree-query-ii#tag-highlight-lang-cpp

/*
 * Segment Tree
 *
 */

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, count;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int count) {
 *         this->start = start;
 *         this->end = end;
 *         this->count = count;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and 
     *                         an segment / interval
     *@return: The count number in the interval [start, end] 
     */
    int query(SegmentTreeNode *root, int start, int end) {
        // write your code here
        if (root == NULL)
            return 0;

        if (root->end < start || root->start > end)
            return 0;
  
        if (root->start >= start && root->end <= end)
            return root->count;

        return query(root->left, start, end) + query(root->right, start, end);
    }
};

// Conclusion:
//





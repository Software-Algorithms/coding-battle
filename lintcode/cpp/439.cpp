// 439. Segment Tree Build II
// https://www.lintcode.com/problem/segment-tree-build-ii/description
// https://www.jiuzhang.com/solutions/segment-tree-build-ii#tag-highlight-lang-cpp

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
     * @param A: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int> &A) {
        // write your code here
        return buildTree(A, 0, A.size()-1);
    }

private:
    SegmentTreeNode * buildTree(vector<int>& A, int start, int end) {
        if (start > end) return NULL;

        SegmentTreeNode *node = new SegmentTreeNode(start, end, A[start]);
        if (start == end) return node;
        
        int mid = (start + end) / 2;
        node->left = buildTree(A, start, mid);
        node->right = buildTree(A, mid+1, end);
        if (node->left && node->left->max > node->max)
            node->max = node->left->max;
        if (node->right && node->right->max > node->max)
            node->max = node->right->max;
        return node;
    }
};
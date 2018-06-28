// 201. Segment Tree Build
// https://www.lintcode.com/problem/segment-tree-build/description
// https://www.jiuzhang.com/solutions/segment-tree-build

/*
 * Segment Tree
 *
 */

class SegmentTreeNode {
public:
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
}

class Solution {
public:
    /*
     * @param start: start value.
     * @param end: end value.
     * @return: The root of Segment Tree.
     */
    SegmentTreeNode * build(int start, int end) {
        // write your code here
        if(start > end) return NULL;
        if(start == end) {
            SegmentTreeNode *node = new SegmentTreeNode(start, end);
            return node;
        }
        int mid = start + (end - start) / 2;
        SegmentTreeNode *node = new SegmentTreeNode(start, end);
        node->left = build(start, mid);
        node->right = build(mid+1, end);
        return node;
    }
};

// Conclusion:
// Concept Implementation.





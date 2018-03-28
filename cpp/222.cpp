/**
 * Tree
 *
 * Ref: https://leetcode.com/problems/count-complete-tree-nodes/discuss/62056/68ms-C++-solution-using-binary-search-with-brief-explanation.
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *temp = root;
        int height = 0, count = 0, level;
        while(temp) {
            temp = temp->left;
            height ++;
        }
        temp = root;
        level = height - 2;
        while(level >= 0) {
            TreeNode *left = temp->left;
            for(int i = 0;i < level;i ++) {
                left = left->right;
            }
            if(left) {
                temp = temp->right;
                count += (1 << level);
            } else {
                temp = temp->left;
            }
            level --;
        }
        if(temp) count ++;
        return (1 << (height - 1)) + count - 1;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
	    return sum(root, 0);
    }

    int sum(TreeNode* node, int s) {
    	if (!node) return 0;
    	if (!node->right && !node->left) return s*10 + node->val;
    	return sum(node->left, s*10 + node->val) + sum(node->right, s*10 + node->val);        
    }
};
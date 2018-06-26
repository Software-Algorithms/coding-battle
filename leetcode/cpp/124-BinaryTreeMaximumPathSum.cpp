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
    int maxVal;
    
    int maxPathSum(TreeNode* root) {
        maxVal = INT_MIN;
        maxDown(root);
        return maxVal;
    }
    
    int maxDown(TreeNode* root) {
        if(!root) return 0;
        int leftmax = max(0, maxDown(root->left));
        int rightmax = max(0, maxDown(root->right));
        maxVal =  max(maxVal, leftmax + root->val + rightmax);
        return max(leftmax, rightmax) + root->val;
    }
};
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(&preorder[0], &inorder[0], (int)preorder.size());
    }
    
    TreeNode* buildTree(int *preorder, int *inorder, int n) {
        if(n == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int rootIndex;
        for(rootIndex = 0; inorder[rootIndex] != root->val; ++rootIndex);
        root->left = (rootIndex == 0) ? NULL : buildTree(preorder+1, inorder, rootIndex);
        root->right = (rootIndex == n-1) ? NULL : buildTree(preorder+rootIndex+1, inorder+rootIndex+1, n-rootIndex-1);
        return root;
    }
};


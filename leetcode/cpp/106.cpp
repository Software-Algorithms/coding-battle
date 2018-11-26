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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(&inorder[0], &postorder[0], (int)inorder.size());
    }
    
    TreeNode* buildTree(int *inorder, int *postorder, int n) {
        if(n == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[n-1]);
        int rootIndex;
        for(rootIndex = 0; inorder[rootIndex] != root->val; ++rootIndex);
        root->left = (rootIndex == 0) ? NULL : buildTree(inorder, postorder, rootIndex);
        root->right = (rootIndex == n-1) ? NULL : buildTree(inorder+rootIndex+1, postorder+rootIndex, n-rootIndex-1);
        return root;
    }
};
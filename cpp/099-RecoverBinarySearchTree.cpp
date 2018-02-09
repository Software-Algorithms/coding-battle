/*
 * DFS
 *
 * Space: O(n) ?
 *
 */

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
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;
    void recoverTree(TreeNode* root) {
        prev = NULL;
        first = NULL;
        second = NULL;
        // In order traversal to find the two elements
        traverse(root);
        // Swap the values of the two nodes
        if (first && second) swap(first->val, second->val);
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);

        // MAIN BODY
        if (!prev) prev = root;
        else {
            if (prev->val > root->val) {
                if (!first) first = prev;
                second = root;
            }
            prev = root;
        }
        // End of MAIN BODY

        traverse(root->right);        
    }
};
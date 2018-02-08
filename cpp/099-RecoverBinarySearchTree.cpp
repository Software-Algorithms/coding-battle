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
    TreeNode* firstElement;;
    TreeNode* secondElement;;
    TreeNode* prevElement = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        // In order traversal to find the two elements
        traverse(root);
        // Swap the values of the two nodes
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }
    
    void traverse(TreeNode* root) {
        if (!root) return;
        traverse(root->left);
        
        // MAIN BODY
        if (!firstElement && prevElement->val >= root->val) {
            firstElement = prevElement;
        }
        if (firstElement && prevElement->val >= root->val) {
            secondElement = root;
        }        
        prevElement = root;
        // End of MAIN BODY

        traverse(root->right);        
    }
};
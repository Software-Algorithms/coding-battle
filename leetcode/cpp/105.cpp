/*
 * Tree, Recursion
 *
 */

// version 1:
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
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

// version 2:
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder.data(), inorder.data(), (int)preorder.size());
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


/*****
Take-away:
When we use this way, "int *arr = &preorder[0]", we are assuming that the vector, "preorder", is not empty. So before we 
apply it, we need to separeatedly consider the empty case as in version 1.
There is actually 2 elegant ways to implement this or to convert a vector to an array:
(a) std::vector<double> v; double* a = v.data();
(b) double arr[100];
    std::copy(v.begin(), v.end(), arr);
Well, aprrarently, the first way is more recommended.
*****/


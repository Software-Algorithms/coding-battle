/**
 * Tree, DFS
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        string path;
        if(root) dfs(root, path, ret);
        return ret;
    }

    void dfs(TreeNode* root, string path, vector<string>& ret) {
        if(!root->left && !root->right) ret.push_back(path+to_string(root->val));
        if(root->left) dfs(root->left, path+to_string(root->val)+"->", ret);
        if(root->right) dfs(root->right, path+to_string(root->val)+"->", ret);
    }
};
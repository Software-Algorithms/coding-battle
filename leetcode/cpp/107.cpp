/*
 * BFS, Bianry Tree
 *
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (root == NULL) return res;

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> oneLevel;
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = q.front();
                q.pop();
                oneLevel.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.insert(res.begin(), oneLevel);
        }
        return res;
    }
};
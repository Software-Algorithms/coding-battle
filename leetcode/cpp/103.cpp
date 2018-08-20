/*
 * Binary Tree, BFS
 *
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        
        vector<vector<int>> result;
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;
    
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();
    
                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);
                level[index] = node->val;
                
                if (node->left) nodesQueue.push(node->left);
                if (node->right) nodesQueue.push(node->right);
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back(level);
        }
        return result;        
    }
};

/*****
Idea:
这里用了两个小的trick让代码变得elegant
1) 用一个标志位来提示该行的存储是从左至右或者相反；
2) level初始化的时候先准备好数据空间，那么只要确定序号就可以存储。
*****/


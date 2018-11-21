/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Array, Stack
 *
 * Idea:
 *    - DP.
 *    - version 2: Geeksforgeeks
 *    - 基本思路与version 1一致，执行稍有区别，品味下两种风格。
 *
 * Complexity:
 *    O()
 *
 */
class Solution {
private:
    TreeNode* clone(TreeNode* root){
        if(!root) return NULL;
        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>(0);
        vector<TreeNode*> res(1, NULL);
        for(int i = 1; i <= n; i++) {
            vector<TreeNode*> tmp;
            for(int j = 0; j < res.size(); j++) { // DP
                // add old tree to left
                TreeNode* oldroot = res[j];
                TreeNode* root = new TreeNode(i);
                TreeNode* target = clone(oldroot);
                root->left = target;
                tmp.push_back(root);

                // add to right
                if(oldroot){
                    TreeNode* tmpold = oldroot;
                    while(tmpold->right){
                        TreeNode* newnode = new TreeNode(i);
                        TreeNode* tright = tmpold->right;
                        tmpold->right = newnode;
                        newnode->left = tright;
                        TreeNode *target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = tright;
                        tmpold = tmpold->right;
                    }
                    // new node as the rightmost leave node
                    tmpold->right = new TreeNode(i);
                    TreeNode *target = clone(oldroot);
                    tmp.push_back(target);
                    tmpold->right = NULL;
                }
            }
            res = tmp;
        }
        return res;
    }
};

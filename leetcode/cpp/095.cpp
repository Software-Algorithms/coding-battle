/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/24/2018
 *
 * Data structure:
 *    Array, Stack
 *
 * Idea:
 *    - DP.
 *    - 与I的思想相同。
 *    - Recursion.
 *    - 若不用指针，全部实例化的话会存在大量的对象拷贝，要调用拷贝构造函数来重构vector。
 *
 * Complexity:
 *    O()
 *
 */
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return {};
        return *generateTreesDFS(1, n);
    }
    vector<TreeNode*> *generateTreesDFS(int start, int end) {
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if (start > end) subTree->push_back(NULL);
        else {
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> *leftSubTree = generateTreesDFS(start, i - 1);
                vector<TreeNode*> *rightSubTree = generateTreesDFS(i + 1, end);
                for (int j = 0; j < leftSubTree->size(); ++j) {
                    for (int k = 0; k < rightSubTree->size(); ++k) {
                        TreeNode *node = new TreeNode(i);
                        node->left = (*leftSubTree)[j];
                        node->right = (*rightSubTree)[k];
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};

/**
 * Code description
 *
 * Author: xpharry
 * Date: 11/11/2018
 *
 * Data structure:
 *    Binary Search Tree
 *
 * Idea:
 *    - DP.
 *    - Iteration.
 *    - The basic idea is that we can construct the result of n node tree just
 *      from the result of n-1 node tree.
 *      Here’s how we do it: only 2 conditions:
 *
 *      > The nth node is the new root, so newroot->left = oldroot;
 *      > The nth node is not root, we traverse the old tree, every time the node
 *        in the old tree has a right child, we can perform: old node->right = nth
 *        node, nth node ->left = right child; and when we reach the end of the
 *        tree, don’t forget we can also add the nth node here.
 *
 *      One thing to notice is that every time we push a TreeNode in our result,
 *      I push the clone version of the root, and I recover what I do to the old
 *      node immediately. This is because you may use the old tree for several
 *      times.
 *
 * Complexity:
 *    O()
 *
 */
class Solution {
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
                        tmpold->right = tright; // recover to base
                        tmpold = tmpold->right; // move to right side
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

    TreeNode* clone(TreeNode* root){
        if(!root) return NULL;
        TreeNode* newroot = new TreeNode(root->val);
        newroot->left = clone(root->left);
        newroot->right = clone(root->right);
        return newroot;
    }
};

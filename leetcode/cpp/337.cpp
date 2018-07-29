/*
 * Tree, DFS
 *
 */
class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return robHelper(root, l, r);
    }

private:
    int robHelper(TreeNode* root, int& l, int& r) {
        if(!root) return 0;

        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = robHelper(root->left, ll, lr);
        r = robHelper(root->right, rl, rr);

        return max(root->val+ll+lr+rl+rr, l+r);
    }
};

/*****
Conclusion:

Idea:
Divide and Conquer
第一种情况：取得当前节点值，那么必须跳过当前节点的左右子节点取值；
第二种情况：不取当前节点值，那么可以取左右节点值，递归到左右子树。

Reference:
...
*****/





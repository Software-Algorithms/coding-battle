/*
 * DFS
 *
 */
class Solution {
public:
    int maxVal;
    
    int maxPathSum(TreeNode* root) {
        maxVal = INT_MIN;
        maxDown(root);
        return maxVal;
    }
    
    int maxDown(TreeNode* root) {
        if(!root) return 0;
        int leftmax = max(0, maxDown(root->left));
        int rightmax = max(0, maxDown(root->right));
        maxVal =  max(maxVal, leftmax + root->val + rightmax);
        return max(leftmax, rightmax) + root->val;
    }
};


/*****
Idea:
这道题容易想到用dfs来解，难点在于，路径起始点可以是任何节点，可以不经过根节点。
最简单的，如果是一个空节点，那么路径和为0。
如果是叶子节点，那么，最小路径和也很好找，当前节点值与0比较即可。
如果是分别有一个左右子节点，那么比较的是三个节点的邻接组合。
再网上回溯，会发现，要经过父节点的话，子节点的左右子几点需要做取舍，因为路径不能分叉。
如：
    4
   / \
  11 13
 / \
7   2
回溯到4，要舍去2，因为7>2。
所以设计一个回溯函数，返回左右路径的较大的那个。

Reference:
Grandyang: http://www.cnblogs.com/grandyang/p/4280120.html
*****/


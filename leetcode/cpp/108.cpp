/*
 * Tree
 *
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return construct(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* construct(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = construct(nums, left, mid - 1);
        root->right = construct(nums, mid + 1, right);
        return root;
    }
};


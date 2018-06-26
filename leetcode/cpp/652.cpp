/*
 * Tree Serialization + Hash Table
 *
 */
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> m; // serialized node --> frequency
        serializeNode(root, m, res);
        return res;
    }
    
    string serializeNode(TreeNode* node, unordered_map<string, int> &m, vector<TreeNode*> &res) {
        if(!node) return "#";
        string str = to_string(node->val) + "," 
            + serializeNode(node->left, m, res) + ","
            + serializeNode(node->right, m, res);
        if(m[str] == 1) res.push_back(node);
        m[str]++;
        return str;
    }
};

// Conclusion:
// Tree Serialization by Preorder Traversal
// Hash Table is used to check repeating.
// Interesting to dig deep about why we need "," when serialization.




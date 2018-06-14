/*
 * Serialize Tree to String
 *
 */
 
// version 1:
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t) return "";
        string res = "";
        serialize(t, res);
        return string(res.begin()+1, res.end()-1);
    }
    
    void serialize(TreeNode* t, string& res) {
        if(!t) return;
        res += "(" + to_string(t->val);
        if(!t->left && t->right) res += "()";
        serialize(t->left, res);
        serialize(t->right, res);
        res += ")";
    }
};

// version 2:
class Solution {
public:
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string res = to_string(t->val);
        if (!t->left && !t->right) return res;
        res += "(" + tree2str(t->left) + ")";
        if (t->right) res += "(" + tree2str(t->right) + ")";
        return res;
    }
};

// Conclusion:
// Easy.


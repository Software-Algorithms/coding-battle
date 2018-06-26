/*
 * Tree Deserialization
 *
 */
class Solution {
public:
    TreeNode* str2tree(string s) {
        if(s == "") return nullptr;
        
        int pos = s.find('(');
        if(pos == string::npos) {
            int val = stoi(s);
            TreeNode* root = new TreeNode(val);
            return root;
        }
        
        int val = stoi(s.substr(0, pos));
        TreeNode* root = new TreeNode(val);
        int start = pos, cnt = 0;
        for(int i = start; i < s.size(); i++) {
            if(s[i] == '(') {
                cnt++;
            } else if (s[i] == ')') {
                cnt--;
                if(cnt == 0 && start == pos) { // '('
                    root->left = str2tree(s.substr(start+1, i-start-1));
                    start = i+1;
                } else if (cnt == 0) { // ')'
                    root->right = str2tree(s.substr(start+1, i-start-1));
                }
            }
        }
        
        return root;
    }
};

// Conclusion:
// String to Tree





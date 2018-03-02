/**
 * Stack
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int longest;
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push(i);
            else {
                if(st.empty()) st.push(i);
                else {
                    if(s[st.top()] == '(') st.pop();
                    else {
                        st.push(i);
                    }
                }
            }
        }
        
        int pre = n, cur;
        if(st.empty()) return n;
        while(!st.empty()) {
            cur = st.top();
            st.pop();
            longest = max(longest, pre - cur - 1);
            pre = cur;
        }
        longest = max(longest, pre);
        
        return longest;
    }
};
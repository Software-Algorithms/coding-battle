/*
 * Monotonous Stack
 *
 */

// version 1: using vector as stack
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        heights.push_back(0);
        vector<int> index;
        
        for(int i = 0; i < heights.size(); i++) {
            while(index.size() > 0 && heights[index.back()] >= heights[i]) {
                int h = heights[index.back()];
                index.pop_back();
                
                int sidx = index.size() > 0 ? index.back() : -1;
                if(h * (i-sidx-1) > ret)
                    ret = h * (i-sidx-1);
            }
            index.push_back(i);
        }
        
        return ret;        
    }
};

// version 2: using stack itself (more general)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.empty()) return 0;
        
        int res = 0;
        stack<int> st; // store the index of ascending heights
        heights.push_back(0); // important; convenient for the last entry
        
        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                int idx = st.top();
                st.pop();
                int width = st.empty() ? i : i-st.top()-1; // how to determin the width?
                res = max(res, width * heights[idx]);
            }
            st.push(i);
        }
        
        return res;
    }
};

// Conclusion:
// 
// 什么时候需要用单调栈（Monotonous Stack）？
// 找每个元素左边或者右边第一个比它自身小/大的元素用单调栈来维护.



 

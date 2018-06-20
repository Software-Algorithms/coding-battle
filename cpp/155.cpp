/*
 * Stack, Design
 *
 */
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(min_st.empty() || x <= min_st.top()) min_st.push(x);
    }
    
    void pop() {
        if(st.top() == min_st.top()) min_st.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
    
private:
    stack<int> st, min_st;
};

// Conclusion:
// stack

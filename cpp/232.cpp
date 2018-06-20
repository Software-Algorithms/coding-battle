/*
 * Stack
 *
 */

// version 1: use one stack
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        stack<int> tmp;
        while (!s.empty()) {
            tmp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!tmp.empty()) {
            s.push(tmp.top());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s.pop();
    }

    // Get the front element.
    int peek(void) {
        return s.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }

private:
    stack<int> s;
};

// Conclusion:
// stack twice --> reverse and reverse -->queue
//
//

// version 2: use two stacks
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        _new.push(x);
    }
    
    void shiftStack() {
        if (_old.empty()) {
            while (!_new.empty()) {
                _old.push(_new.top());
                _new.pop();
            }
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        shiftStack();
        if (!_old.empty()) _old.pop();
    }

    // Get the front element.
    int peek(void) {
        shiftStack();
        if (!_old.empty()) return _old.top();
        return 0;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return _old.empty() && _new.empty();
    }

private:
    stack<int> _old, _new;
};

// Conclusion:
// v1那个解法虽然简单，但是效率不高，因为每次在push的时候，都要翻转两边栈，v2这个方法使用了
// 两个栈_new和_old，其中新进栈的都先缓存在_new中，入股要pop和peek的时候，才将_new中所有元素
// 移到_old中操作，提高了效率。





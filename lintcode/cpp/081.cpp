// 81. Find Median from Data Stream
// https://www.jiuzhang.com/solutions/data-stream-median/#tag-highlight-lang-cpp
// https://www.lintcode.com/problem/data-stream-median/description

/*
 * Heap (priority queue)
 *
 */

// version 1:
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> res;
        for(int num : nums) {
            small.push(num);
            large.push(-small.top());
            small.pop();
            if(small.size() < large.size()) {
                small.push(-large.top());
                large.pop();
            }
            res.push_back(small.top());
        }
        return res;
    }
    
private:
    priority_queue<int> small, large;
};


// version 2: module function
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: the median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        // write your code here
        vector<int> res;
        for(int num : nums) {
            addNum(num);
            res.push_back(small.top()); 
        }
        return res;
    }
    
private:
    priority_queue<int> small, large;
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    int getMedian() {
        return small.top();
    }
};

// Conclusion:
// 1. 保证process过的两个堆，small的容量是大于等于large的，那么每次就直接从small的top去取median，很方便。
// 2. push新值的时候，先push进small，再把small的最大值push进large，保证了全局的顺序性。
// 3. 为了保证始终small的容量是大于等于large的容量，检查两个堆的容量，如果large更大，则将其最小值push进small。





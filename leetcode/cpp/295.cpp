/*
 * Heap (priority_queue), Design
 *
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if(large.size() > small.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > large.size()) {
            return small.top();
        } else {
            return ( small.top() - large.top() ) / 2;
        }
    }
    
private:
    priority_queue<double> small, large; // descending order, top is largest
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */


/*
 * Heap (multi_set: binary search tree), Design
 *
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        large.insert(num);
        small.insert(-*large.begin());
        large.erase(large.begin());
        
        if(small.size() > large.size()) {
            large.insert(-*small.begin());
            small.erase(small.begin());
        }
    }
    
    double findMedian() {
        return small.size() < large.size() ? *large.begin() : 0.5 * (*large.begin() - *small.begin());
    }
    
private:
    multiset<int> small, large;
};
 
// Conclusion:
// Maintain a maxheap and a min heap. The median is only related to the top of the two heaps.
//
// Implement Heap with priority queue or multiset.
// priority_queue<T>
//
// multiset<T>
// Multisets are typically implemented as binary search trees.
// Difference with set<T>: Set and multiset containers sort their elements automatically according
//                         to a certain sorting criterion. The difference between the two is that 
//                         multisets allow duplicates, whereas sets do not.
//                         To use a set or multiset, you must include the header file <set>
// If a special sorting criterion is not passed, the default criterion less is used. The function
// object less sorts the elements by comparing them with operator <.
//
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/4896673.html




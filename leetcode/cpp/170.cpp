/*
 * Hash Table
 *
 * Solution 1:
 */
class TwoSum {
private:
    unordered_map<int, int> m;

public:
    /** Initialize your data structure here. */
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++m[number];
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */   
    bool find(int value) {
        for (auto a : m) {
            int t = value - a.first;
            if ((t != a.first && m.count(t)) || (t == a.first && a.second > 1)) {
                return true;
            }
        }
        return false;
    }
};


/*
 * Solution 2:
 *
 * Similar to Solution 1 by changing unordered_map to unordered_multiset
 *
 * unordered_multiset<T>: contains set of possibly non-unique objects of type Key
 *
 */
class TwoSum {
private:
    unordered_multiset<int> nums;
    
public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (int i : nums) {
            int count = i == value - i ? 1 : 0;
            if (nums.count(value - i) > count) {
                return true;
            }
        }
        return false;        
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
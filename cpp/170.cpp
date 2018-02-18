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
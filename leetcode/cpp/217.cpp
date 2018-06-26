/**
 * Hash Table
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.empty()) return false;

        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i])) return true;
            m[nums[i]] = 1;
        }

        return false;
    }
};


/**
 * Sort
 */
class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=0; i<int(nums.size())-1; i++) {
            if (nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};


/**
 * Set
 */
class Solution {
public:
    bool containsDuplicate4(vector<int>& nums) {
        set<int> mySet;
        // unordered_set<int> mySet;
        // multiset<int> mySet;
        // unordered_multiset<int> mySet;
        for (auto& num: nums) {
            if (mySet.find(num) != mySet.end())
                return true;
            mySet.insert(num);
        }
        return false;
    }
};


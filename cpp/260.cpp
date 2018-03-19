/**
 * Hash Table
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> hash;
        for(int i = 0; i < nums.size(); i++) {
            if(!hash.count(nums[i])) hash[nums[i]] = 1;
            else hash.erase(nums[i]);
        }

        vector<int> ret;
        for(map<int, int>::iterator it = hash.begin(); it != hash.end(); it++) {
            ret.push_back(it->first);
        }

        return ret;
    }
};


/**
 * Bit Manipulation
 */
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int aXorb = 0;  // the result of a xor b;
        for (auto item : nums) aXorb ^= item;
        int lastBit = aXorb & (~(aXorb - 1));  // the last bit that a diffs b
        int intA = 0, intB = 0;
        for (auto item : nums) {
            // based on the last bit, group the items into groupA(include a) and groupB
            if (item & lastBit) intA = intA ^ item;
            else intB = intB ^ item;
        }
        return vector<int>{intA, intB};
    }
};

/*****
 * Tip:
 * the last bit that is '1' can usually be got by:
 * last = r & (~(r-1))
 * Example:
 * r = 1010, r-1 = 1001, ~(r-1) = 0110, r&(~(r-1)) = 0010
 */
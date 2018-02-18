class Solution {
    string get_range(int start, int end)
    {
        return start==end? to_string(start) : to_string(start)+"->"+to_string(end);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int l, r;
        if(nums.size()<1) {
            l = lower, r = upper;
            res.push_back(get_range(l,r));           
            return res;
        }
        
        l = lower, r = nums[0]-1;
        if(l==r) res.push_back(to_string(l));
        if(l<r) res.push_back(to_string(l)+"->"+to_string(r));
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] > 1) {
                l = nums[i-1]+1;
                r = nums[i]-1;
                res.push_back(get_range(l,r));
            }
        }
        
        if(upper > nums[nums.size()-1]) {
            l = nums[nums.size()-1]+1, r = upper;
            res.push_back(get_range(l,r));
        }
        
        return res;
    }
};
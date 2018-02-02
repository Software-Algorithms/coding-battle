class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
        int ret = 0;
        int min_diff = INT_MAX;
        for(int i = 0; i < nums.size()-2; i++){
        	int l = i+1, r = nums.size()-1;
        	while(l < r) {
        		int sum = nums[i]+nums[l]+nums[r];
        		int diff = abs(sum - target);
        		if(diff == 0) return target; // no need to continue
        		if(diff < min_diff){
        			min_diff = diff;
        			ret = sum;
        		}
        		if(sum < target) {
                    l++;
                }
        		else {
                    r--;
                }        		
        	}
        }
        return ret;          
    }
};
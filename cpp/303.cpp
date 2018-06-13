/*
 * DP
 *
 */

//version 1:
class NumArray {
public:
    NumArray(vector<int> nums) {
        dp = nums;
        for (int i = 1; i < nums.size(); ++i) {
            dp[i] += dp[i - 1];
        }        
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? dp[j] : dp[j] - dp[i - 1];
    }

private:
    vector<int> dp;
};

// version 2:
class NumArray {
public:
    NumArray(vector<int> &nums) {
        dp.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
    
private:
    vector<int> dp;
};

// Conclusion:
// Decrease the time complexity of the method that would be called frequntly.
// In version 2, the add-on is to avoid zero check.


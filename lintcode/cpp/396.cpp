// Problem description: https://www.lintcode.com/problem/coins-in-a-line-iii/description
// Problem solution: https://www.jiuzhang.com/solutions/coins-in-a-line-iii

/*
 * DP + Game Theory (博弈类)
 * 记忆 + 区间 搜索
 */

// version 1:
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        int n = values.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        vector<vector<bool>> flag(n+1, vector<bool>(n+1));
        
        int sum = 0;
        for(int now : values) sum += now;
        
        return sum < 2 * memorySearch(values, 0, n - 1, dp, flag);
    }
    
private:
    int memorySearch(vector<int>& values, int left, int right, vector<vector<int>>& dp, vector<vector<bool>>& flag) {
        if(flag[left][right]) return dp[left][right];
        flag[left][right] = true;
        if(left > right) {
            dp[left][right] = 0;
        } else if (left == right) {
            dp[left][right] = values[left];
        } else if(left + 1 == right) {
            dp[left][right] = max(values[left], values[right]);
        } else {
            int pick_left = min(memorySearch(values, left + 2, right, dp, flag),
                                memorySearch(values, left + 1, right - 1, dp, flag))
                            + values[left];
            int pick_right = min(memorySearch(values, left, right - 2, dp, flag),
                                 memorySearch(values, left + 1, right - 1, dp, flag))
                             + values[right];
            dp[left][right] = max(pick_left, pick_right);    
        }
        return dp[left][right];   
    }
};

// Reference:
// jiuzhang
// https://aaronice.gitbooks.io/lintcode/content/dynamic_programming/coins_in_a_line_ii.html





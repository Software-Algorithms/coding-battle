// Problem description: https://www.lintcode.com/problem/coins-in-a-line-ii/description
// Problem solution: https://www.jiuzhang.com/solutions/coins-in-a-line-ii/#tag-highlight-lang-cpp-ii

/*
 * DP + Game Theory(博弈论)
 * 记忆搜索
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
        vector<int> dp(n);
        vector<bool> flag(n);
        int sum = 0;
        for(int now : values) sum += now;
        
        return sum < 2 * memorySearch(values, n, dp, flag);
    }

private:    
    int memorySearch(vector<int>& values, int idx, vector<int>& dp, vector<bool>& flag) { 
        if(flag[idx] == true) return dp[idx];
        flag[idx] = true;
        if(idx == 0)  {
            dp[idx] = 0;  
        } else if(idx == 1) {
            dp[idx] = values[values.size()-1];
        } else if(idx == 2) {
            dp[idx] = values[values.size()-1] + values[values.size()-2]; 
        } else if(idx == 3){
            dp[idx] = values[values.size()-2] + values[values.size()-3]; 
        } else {
            dp[idx] = max(min(memorySearch(values, idx-2, dp, flag), memorySearch(values, idx-3, dp, flag))
                         + values[values.size()-idx],
                         min(memorySearch(values, idx-3, dp, flag), memorySearch(values, idx-4, dp, flag))
                         + values[values.size()-idx] + values[values.size() - idx + 1]);
        }
    
        return dp[idx];
    } 
};

// version 2:
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here
        vector<int> sum, f;
        int n = values.size(), total = 0;
        if (n<3) return true;
        for (int i=0; i<n; ++i) total += values[i];   
        for (int i=0; i<n; ++i) {
            sum.push_back(total);
            total -= values[i];
        }
        f.push_back(sum[n-1]);
        f.push_back(sum[n-2]);
        for (int i=n-3; i>=0; --i)
            f.push_back(max(values[i]+(sum[i+1]-f[n-1-i-1]), values[i]+values[i+1]+(sum[i+2]-f[n-1-i-2])));
        if (f[n-1]<sum[0]-f[n-1]) return false;
        else return true;
    }
};

// Conclusion:
//
// 动态规划4要素:
// 1) State:
//   dp[i] 现在还剩i个硬币，现在当前取硬币的人最后最多取硬币价值
// 2) Function:
//   i 是所有硬币数目
//   sum[i] 是后i个硬币的总和
//   dp[i] = sum[i]-min(dp[i-1], dp[i-2])
// 3) Intialize:
//   dp[0] = 0
//   dp[1] = coin[n-1]
//   dp[2] = coin[n-2] + coin[n-1]
// 4) Answer:
//   dp[n]
//
// Reference:
// jiuzhang
// https://aaronice.gitbooks.io/lintcode/content/dynamic_programming/coins_in_a_line_ii.html





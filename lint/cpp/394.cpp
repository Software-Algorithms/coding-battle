// Problem description: https://www.lintcode.com/problem/coins-in-a-line/description
// Problem solution: https://www.jiuzhang.com/solutions/coins-in-a-line/

/*
 * DP + Game Theory (博弈论)
 *
 */

// version 1: cannot pass due to the Time Limit.
class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        vector<bool> dp(n + 1);
        vector<bool> flag(n + 1);
        return search(n, dp, flag);
    }

    bool search(int i, vector<bool> dp, vector<bool> flag) {
        if (flag[i] == true) {
            return dp[i];
        }
        if (i == 0) {
            dp[i] = false;
        } else if (i == 1) {
            dp[i] = true;
        } else if (i == 2) {
            dp[i] = true;
        } else {
            dp[i] = ! (search(i - 1, dp, flag) && search(i - 2, dp, flag));
        }
        flag[i] = true;
        return dp[i];
    }
};

// version 2:
class Solution {
public:
    /**
     * @param n: An integer
     * @return: A boolean which equals to true if the first player will win
     */
    bool firstWillWin(int n) {
        // write your code here
        vector<int> dp(n + 1, -1); // -1: not visited, 0: lose, 1: success
        return memorySearch(n, dp);
    }

    bool memorySearch(int i, vector<int>& dp) {
        if (dp[i] != -1) {
            return dp[i];
        }
        if (i == 0) {
            dp[i] = 0;
        } else if (i == 1) {
            dp[i] = 1;
        } else if (i == 2) {
            dp[i] = 1;
        } else if (i == 3) {
            dp[i] = 0;
        } else {
            // only consider First player
            if((memorySearch(i-2, dp) && memorySearch(i-3, dp)) || // First: 1 + Second: 1 && // First: 1 + Second: 2
                (memorySearch(i-3, dp) && memorySearch(i-4, dp) )) { // First: 2 + Second: 1 && // First: 2 + Second: 2
                dp[i] = 1;
            } else {
                dp[i] = 0;
            }
        }
        return dp[i];
    }
};

/*
 * Greedy
 *
 */
class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        // write your code here
        if (n%3==0) return false;
        else return true;
    }
};

// Reference:
// jiuzhang
// https://aaronice.gitbooks.io/lintcode/content/dynamic_programming/coins_in_a_line.html





# The Coin Change Problem

## Tag

DP

## Idea



## Code

```cpp
#include <bits/stdc++.h>

using namespace std;

long getWays(long n, vector < long > c){
    // Complete this function
    vector<long> dp(n+1);
    dp[0] = 1;
    for(int i = 0; i < c.size(); i++) {
        for(int j = 1; j <= n; j++) {
            if(j >= c[i]) dp[j] += dp[j-c[i]];
        }
    }
    return dp[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout << ways << endl;
    return 0;
}
```
/*
 * Solution 1:
 * DP
 *
 */
class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3) return 0;
        
        int res = 0, n = A.size();
        int dp1[n] = {0}; // elements such that B[0] < B[1] < .. < B[i]
        int dp2[n] = {0}; // elements such that B[i] > B[i + 1] > .. > B[last]
				
        for(int i = 1; i < n; i++) {
            if(A[i] > A[i-1]) dp1[i] = dp1[i-1] + 1;
        }
        
        for(int i = n - 2; i >= 0; i--) {
            if(A[i] > A[i+1]) dp2[i] = dp2[i+1] + 1;
        }
        
        for(int i = 0; i < n; i++) {
            if(dp1[i] && dp2[i]) {
                res = max(res, dp1[i] + dp2[i] + 1);
            }
        }
        
        return res;        
    }
};

// Conclusion:
// For each position I see it as the top of the mountain, so I use two dp arrays
// to record the increasing or decreasing trend.
// Then traverse once again to bring a mountain up (which has increasing in the left
// and decreasing in the right side).


/*
 * Solution 2:
 * 
 *
 */
class Solution {
public:
    int longestMountain(vector<int>& A) {   
        if (A.size() < 3) return 0;
                
        int res = 0, up = 0, down = 0;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i-1]) {
                if (down > 0) { // status change
                    up = 0;
                }
                down = 0;
                ++up;
            } else if (A[i] < A[i-1]) {
                ++down;
            } else {
                up = down = 0;
            }            
            
            if (up > 0 && down > 0) {
                res = max(res, up+down+1);
            }
        }
        
        return res; 
    }
};

// Conclusion
// One pass. Here we check if there is a mountain ending here.
// Go up first and down then.



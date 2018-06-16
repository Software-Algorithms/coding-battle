/*
 * Two Pointers
 * One pass, O(n)
 */
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max_dist = 0;
        int prev = -1, idx = 0, n = seats.size();
        
        while(idx < n) {
            int cur_dist = 0;
            if(seats[idx] == 1) {
                if(prev == -1) cur_dist = idx;
                else {
                    int mid = prev + (idx - prev)/2;
                    cur_dist = min(mid-prev, idx-mid);
                }
                prev = idx;
            }
            max_dist = max(max_dist, cur_dist);
            idx++;
        }
        max_dist = max(max_dist, n-prev-1);
        
        return max_dist;
    }
};

// Conclusion:
// Two Pointers
// 注意首尾。
//

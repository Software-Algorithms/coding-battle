class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> num(n,1);
        
        // 1st traversal, from left to right
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) num[i] = num[i-1] + 1;
        }
        
        // 2nd travesal, from right to left
        for(int i = n-1; i > 0; i--) {
            if(ratings[i-1] > ratings[i])
                num[i-1] = max(num[i] + 1, num[i-1]);
        }
        
        // 3nd travesal, collect result
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += num[i];
        }
        
        return res;
    }
};
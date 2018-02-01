class Solution {
public:
    int reverse(int x) {
        int y = abs(x);
        int res = 0;
        while(y) {
            if(res*10/10 != res) // avoid overflow before *10
                return 0;
            res = res*10 + y%10;
            y /= 10;
        }
        if(x<0) res = -res;
        return res;        
    }
};
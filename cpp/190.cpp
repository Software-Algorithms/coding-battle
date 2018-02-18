class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0) return 0;
        
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = res<<1;
            res = ((n&1) == 1) ? res + 1 : res;
            n = n>>1;
        }
        
        return res;        
    }
};
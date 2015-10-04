class Solution {
public:
    bool isPowerOfTwo(int n) {
        while(n%2) {
        	n /= 2;
        }
        if(n == 1)
        	return true;
        return false;
    }
};
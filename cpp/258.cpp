/**
 * Math
 */
class Solution {
public:
    int addDigits(int num) {
    	return num <= 9 ? num : ( num%9 != 0 ? num%9 : 9 );
    }
};
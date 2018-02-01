class Solution {
public:
    int addDigits(int num) {
    	int sum = 0;
    	while(sum>9) {
    		while(num/10) {
    			sum += num%10;
    			num /= 10; 
    		}
    	}
    	return sum;
    }
};
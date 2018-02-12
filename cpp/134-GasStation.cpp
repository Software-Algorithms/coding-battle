class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i, j;
        for(i = 0; i < n; i +=j) { // the gas station which it starts from
        	int gas_left = 0;
        	for(j = 1; j <= n; j++) { // number of stations passed
        	    int k = (i+j-1)%n;
        		gas_left += gas[k] - cost[k];
        		if(gas_left < 0) break;
        	}
        	if(j > n) return i;
        }
        return -1;
    }
};
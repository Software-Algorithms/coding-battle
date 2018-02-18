class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty()) return vector<int>({-1, -1});
        for(int i = 0; i < numbers.size()-1; i++) {
            int l=i+1, r=numbers.size()-1, gap=target-numbers[i];
            while(l <= r) {
                int m = l+(r-l)/2;
                if(numbers[m] == gap) return vector<int>({i+1, m+1});
                if(numbers[m] > gap) r = m-1;
                else l = m+1;
            }
        }
        return vector<int>({-1, -1});
    }
};
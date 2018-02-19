/*
 * Binary Search
 *
 * O(nlgn)
 *
 */
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


/*
 * Two Pointers
 *
 * O(n)
 *
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l + 1, r + 1};
            else if (sum < target) ++l;
            else --r;
        }
        return {};
    }
};
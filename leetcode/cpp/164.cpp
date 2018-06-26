/*
 * Sort
 *
 * Bucket Sort
 */
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        
        // get the min and max values of the set
        auto lu = minmax_element(nums.begin(), nums.end());
        int l = *lu.first, u = *lu.second;

        // bucket sort
        int gap = (u-l) / (n-1) + 1;
        int m = (u-l) / gap + 1; // number of buckets
        vector<int> bucketMin(m, INT_MAX);
        vector<int> bucketMax(m, INT_MIN);

        for(int num : nums) {
            int k = (num-l) / gap;
            if(num < bucketMin[k]) bucketMin[k] = num;
            if(num > bucketMax[k]) bucketMax[k] = num;
        }

        // compute the max gap
        int maxGap = bucketMax[0] - bucketMin[0];
        int i = 0, j;
        while(i < m) {
            j= i+1;
            while( (j < m) && (bucketMin[j] == INT_MAX) && (bucketMax[j] == INT_MIN) ) {
                j++;
            }
            if(j == m) break;

            maxGap = max(bucketMin[j] - bucketMax[i], maxGap);

            i = j;
        }

        return maxGap;
    }
};
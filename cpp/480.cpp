/*
 * Heap (priortity_queue / multiset)
 *
 */

// version 1:
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<int> small, large;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (small.count(nums[i - k])) small.erase(small.find(nums[i - k]));
                else if (large.count(nums[i - k])) large.erase(large.find(nums[i - k]));
            }
            if (small.size() <= large.size()) {
                if (large.empty() || nums[i] <= *large.begin()) small.insert(nums[i]);
                else {
                    small.insert(*large.begin());
                    large.erase(large.begin());
                    large.insert(nums[i]);
                }
            } else {
                if (nums[i] >= *small.rbegin()) large.insert(nums[i]);
                else {
                    large.insert(*small.rbegin());
                    small.erase(--small.end());
                    small.insert(nums[i]);
                }
            }
            if (i >= (k - 1)) {
                if (k % 2) res.push_back(*small.rbegin());
                else res.push_back(((double)*small.rbegin() + *large.begin()) / 2);
            }
        }
        return res;
    }
};

// version 2:
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        multiset<double, greater<double>> small, large;
        
        for(int i = 0; i < nums.size(); i++) {
            if(small.size() + large.size() < k) {
                small.insert(nums[i]);
                large.insert(-*small.begin());
                small.erase(small.begin());
                if(small.size() < large.size()) {
                    small.insert(-*large.begin());
                    large.erase(large.begin());
                }
            }
            if(small.size() + large.size() == k) {
                if(k % 2 == 1) res.push_back(*small.begin());
                else res.push_back((*small.begin() - *large.begin())/2);
                if(small.count(nums[i-k+1])) small.erase(small.find(nums[i-k+1]));
                else large.erase(large.find(-nums[i-k+1]));
            }
        }
        
        return res;
    }
};

// Conlcusion:
// 把插入新值和删除元素分开。




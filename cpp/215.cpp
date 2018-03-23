/**
 * Divide and Conquer
 *
 * Partition in Quick Sort
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while(true) {
            int pos = partition(nums, left, right);
            if(pos + 1 == k) return nums[pos];
            if(pos + 1 > k) right = pos - 1;
            else left = pos + 1;
        }
        return -1;
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while(l <= r) {
            if(nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if(nums[l] >= pivot) l++;
            if(nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};


/**
 * Heap / Priority Queue
 *
 */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for(int i = 0; i < nums.size(); i++) {
            minheap.push(nums[i]);
            if(minheap.size() > k) {
                minheap.pop();
            }
        }
        return minheap.top();
    }
};
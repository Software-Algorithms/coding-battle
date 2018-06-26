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
// Conclusion:
// This method is an incomplete implementation of Quick Sort Algorithm.
// We must be very familiar with the idea of Quick Sort process especially
// the Partition Algorithm inside.
// Quick Sort is a typical Divide and Conquer Algorithm. For an array, it
// is divided several subarray until sorted by the partition function.
// The partition function is to transfer one specified element (could be
// the 1st one, last one or even a random one), to its ordered position.
// If the array is small enough for instance there are only two. It would be
// sorted after one partition operation.
// For this problem we only want the Kth (1 based) element is right ordered.
// So the sorting can be ended here.


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
// Conclusion:
// Priority queue - Priority queues are a type of container adaptors,
// specifically designed such that its first element is always the 
// greatest of the elements it contains, according to some strict weak
// ordering criterion.

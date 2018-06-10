/*
 * Solution 1:
 *
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();
        if(n % 2 == 1) {
            return findKth(nums1, nums2, 0, 0, n/2+1);
        } else {
            return (findKth(nums1, nums2, 0, 0, n/2) + findKth(nums1, nums2, 0, 0, n/2+1)) / 2;
        }
    }
    
    double findKth(vector<int>& nums1, vector<int>& nums2, int st1, int st2, int k) {
        if(nums1.size() - st1 > nums2.size() -st2) return findKth(nums2, nums1, st2, st1, k);
        if(nums1.size() == st1) return nums2[st2+k-1];
        if(k == 1) return min(nums1[st1], nums2[st2]);
        int pa = min(st1+k/2, int(nums1.size())), pb = st2+k-pa+st1;
        if(nums1[pa-1] < nums2[pb-1]) return findKth(nums1, nums2, pa, st2, k+st1-pa);
        else return findKth(nums1, nums2, st1, pb, k+st2-pb);
    }
};


/*
 * Solution 2:
 * Binary Search
 *
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        if (n == 0) return ((double)nums1[(m - 1) / 2] + (double)nums1[m / 2]) / 2.0;
        int left = 0, right = n * 2;
        while (left <= right) {
            int mid2 = (left + right) / 2;
            int mid1 = m + n - mid2;
            double L1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double L2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double R1 = mid1 == m * 2 ? INT_MAX : nums1[mid1 / 2];
            double R2 = mid2 == n * 2 ? INT_MAX : nums2[mid2 / 2];
            if (L1 > R2) left = mid2 + 1;
            else if (L2 > R1) right = mid2 - 1;
            else return (max(L1, L2) + min(R1, R2)) / 2;
        }
        return -1;
    }
};


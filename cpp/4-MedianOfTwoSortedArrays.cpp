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
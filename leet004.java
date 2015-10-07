public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int[] nums = new int[m+n];

        int i = 0, j = 0, k = 0;
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                nums[k] = nums1[i];
                i++;
            } else {
                nums[k] = nums2[j];
                j++;
            }
            k++;
        }
        
        while (i < m) {
            nums[k] = nums1[i];
            i++;
            k++;
        }
        
        while (j < n) {
            nums[k] = nums2[j];
            j++;
            k++;
        }
        
        //Arrays.sort(nums);
        if(nums.length%2 == 1)
            return nums[(nums.length-1)/2];
        return  ( nums[(nums.length-2)/2] + nums[nums.length/2] ) / 2.0;
    }
}
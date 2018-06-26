/*
 * Binary Search
 *
 */
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(A[mid-1] < A[mid] && A[mid] > A[mid+1]){
                return mid;
            } else if (A[mid-1] < A[mid]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
};

//
//





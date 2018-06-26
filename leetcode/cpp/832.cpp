/*
 * Array
 *
 */
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        if(A.empty() || A[0].empty()) return A;
        for(int i = 0; i < A.size(); i++) {
             for(int j = 0; j < A[0].size()/2; j++) {
                 swap(A[i][j], A[i][A[0].size()-j-1]);
                 A[i][j] = A[i][j]==1 ? 0 : 1;
                 A[i][A[0].size()-j-1] = A[i][A[0].size()-j-1]==1 ? 0 : 1;
             }
             if(A[0].size()%2 == 1) A[i][A[0].size()/2] = A[i][A[0].size()/2]==1 ? 0 : 1;
        }
        return A;
    }
};

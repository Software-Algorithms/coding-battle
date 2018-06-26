class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curRow(rowIndex+1,0);
        for(int i = 0; i <= rowIndex; i++) {
            curRow[0] = 1;
            for(int j = i; j >= 1; j--) {
                curRow[j] = curRow[j-1] + curRow[j];
            }
        }
        return curRow;
    }
};
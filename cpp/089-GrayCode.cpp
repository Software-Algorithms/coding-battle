class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(1);
        for(int i = 0; i < n; i++) {
            int inc = 1 << i;
            int size = ret.size();
            for(int j = size-1; j >= 0; j--) {
                ret.push_back(ret[j] | inc);
            }
        }
        return ret;
    }
};
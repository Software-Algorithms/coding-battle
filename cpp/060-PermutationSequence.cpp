class Solution {
public:
    string getPermutation(int n, int k) {
        int mod = 1;
        string s;
        
        // 先得到n!和候选数字列表
        for(int i = 1; i <= n; i++){
            mod = mod * i;
            s.push_back(i + '0');
        }
        
        // 将k先减1方便整除
        k--;
        string res;
        for(int i = 0; i < n ; i++){
            mod = mod / (n - i);
            // 得到当前应选数字的序数
            int first = k / mod;
            // 得到用于计算下一位的k
            k = k % mod;
            res.push_back(s[first]);
            // 在列表中移出该数字
            s.erase(s.begin()+first);
        }
        return res;       
    }
};
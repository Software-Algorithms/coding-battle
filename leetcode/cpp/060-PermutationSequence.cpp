/*
 * Math
 *
 * Time: O(n), Space: O(n)
 *
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        int mod = 1;
        string s;
        
        // compute n! and construct candidate digit list
        for(int i = 1; i <= n; i++){
            mod = mod * i;
            s.push_back(i + '0');
        }
        
        // k-- to adapt 0 based ordering in array
        k--;
        string res;
        for(int i = 0; i < n ; i++){
            mod = mod / (n - i);
            // the index of current digit
            int index = k / mod;
            // update k for next iteration
            k = k % mod;
            res.push_back(s[index]);
            // remove the used digit
            s.erase(s.begin()+index);
        }
        return res;       
    }
};
/*
 * String
 *
 */
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = n / 2; i >= 1; --i) {
            if (n % i == 0) { // i is the length of the substr
                int m = n / i; // m is the number of the substring if exits
                string t = "";
                for (int j = 0; j < m; ++j) {
                    t += s.substr(0, i); 
                }
                if (t == s) return true;
            }
        }
        return false;        
    }
};

// Conclusion:
// 子字符串长度最长是n/2，如果很快有这个觉悟，题目就不难下手了。
// sub = s.substr(0, i)
// 再组合到原来的长度做比较。
// 事实上是反证法的应用。
//
//




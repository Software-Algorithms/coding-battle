/*
 * Two Pointers (Sliding Window), Hash Table, String
 *
 */

// version 1:
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int res = 0, left = 0;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); ++i) {
            m[s[i]] = i;
            while (m.size() > k) {
                if (m[s[left]] == left) m.erase(s[left]);
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;        
    }
};

// version 2: in lintcode
class Solution {
public:
    /**
     * @param s: A string
     * @param k: An integer
     * @return: An integer
     */
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        // write your code here
        int max_len = 0;
        int start = 0;
        unordered_map<char, int> m;

        for(int i = 0; i < s.size(); i++) {
            m[s[i]] = i;
            while(m.size() > k) {
                if(m[s[start]] == start) m.erase(s[start]);
                start++;
            }
            max_len = max(max_len, i - start + 1);
        }
        
        return max_len;
    }
};

// Conlusion:
// 窗口的大小变化取决于结果是要求最大长度还是最小长度：
// 1. 最大长度，窗口从大往小变化，移动左边界；
// 2. 最小长度，窗口从小往大变化，移动右边界。
//
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/5185561.html
//            http://www.cnblogs.com/grandyang/p/5351347.html




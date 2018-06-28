/*
 * Two Pointers (Sliding Window)
 *
 */

// version 1:
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> m;
        // Statistic for count of char in t
        for (auto c : t) m[c]++;
        // counter represents the number of chars of t to be found in s.
        size_t start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        size_t size = s.size();
    
        // Move end to find a valid window.
        while (end < size) {
            // If char in s exists in t, decrease counter
            if (m[s[end]] > 0)
                counter--;
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            m[s[end]]--;
            end++;
            // When we found a valid window, move start to find smaller window.
            while (counter == 0) {
                if (end - start < minLen) {
                    minStart = start;
                    minLen = end - start;
                }
                m[s[start]]++;
                // When char exists in t, increase counter.
                if (m[s[start]] > 0)
                    counter++;
                start++;
            }
        }
        if (minLen != INT_MAX)
            return s.substr(minStart, minLen);
        return "";      
    }
};

// version 2: in lintcode
class Solution {
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
        int min_start = 0, min_len = INT_MAX;
        int end = 0, count = target.size();
        
        // hash table to record target string
        unordered_map<char, int> m;
        for(char c : target) {
            m[c]++;
        }

        for(int i = 0; i < source.size(); i++) {
            while(end < source.size() && count > 0) {
                if(m[source[end]] > 0) {
                    count--;
                }
                m[source[end]]--;
                end++;
            }
            if(count == 0 && end - i < min_len) {
                min_start = i;
                min_len = min(min_len, end - i);
            }
            m[source[i]]++;
            if(m[source[i]] > 0) count++;
        }
        
        return min_len == INT_MAX ? "" : source.substr(min_start, min_len);
    }
};

// Conclusion:
// hash在这里维护了一个window，右边界移动，次数减1，左边界移动，次数加1，表示需要与目标字符串匹配的个次数变化；
// 比如刚开始，window是空的，代表着与目标字符串ABC有（A：1，B：1，C：1）的差距，匹配到一个目标字符，对应+1。
// 同时维护它的起始点和长度，一旦符合条件（count == 0）就更新答案。
//
// Reference:
// Laioffer: https://youtu.be/9qFR2WQGqkU (very clearly explained)





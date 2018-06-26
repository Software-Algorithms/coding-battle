/*
 * String
 *
 */
 
// version 1:
class Solution {
public:
    int lengthLongestPath(string input) {
        int res = 0, n = input.size(), level = 0;
        unordered_map<int, int> m {{0, 0}};
        for (int i = 0; i < n; ++i) {
            int start = i;
            while (i < n && input[i] != '\n' && input[i] != '\t') ++i;
            if (i >= n || input[i] == '\n') {
                string t = input.substr(start, i - start);
                if (t.find('.') != string::npos) {
                    res = max(res, m[level] + (int)t.size());
                } else {
                    ++level;
                    m[level] = m[level - 1] + (int)t.size() + 1;
                }
                level = 0;
            } else {
                ++level;
            }
        }
        return res;        
    }
};

// Reference:
// http://www.cnblogs.com/grandyang/p/5806493.html

// version 2:
class Solution {
public:
    int lengthLongestPath(string input) {
        int maxlen = 0, count = 0, level = 1;
        bool isFile = false;
        unordered_map<int, int> levelLength;
        
        int i = 0;
        int length = input.size();
        while (i < length) {
            while (input[i] == '\t') {
                ++level;
                ++i;
            }
            
            while (i < length && input[i] != '\n') {
                if (input[i] == '.')
                    isFile = true;
                
                ++count;
                ++i;
            }
            
            if (isFile) {
                maxlen = max(maxlen, levelLength[level - 1] + count);
            } else {
                levelLength[level] = levelLength[level - 1] + count + 1;
            }
            
            count = 0;
            level = 1;
            isFile = false;
            
            ++i;
        }
        
        return maxlen;
    }
};

// Conclusion:
//
// Reference:
// https://youtu.be/5Nfbu6rg9v0
// https://github.com/jzysheep/LeetCode/blob/master/388.%20Longest%20Absolute%20File%20Path.cpp
//
//




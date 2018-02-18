class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(), n = t.size();
        if (m > n) return isOneEditDistance(t, s);
        if (n - m > 1 || s == t) return false;
        for (int i = 0; i < m; i++)
            if (s[i] != t[i]) {
                if (m == n) s[i] = t[i];
                else s.insert(i, 1, t[i]);
                break;
            }
        return s == t || s + t[n - 1] == t;       
    }
};
/*
 * Hash Table
 *
 *
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int, int> map;
        int len = s.length();
        for(int i = 0; i <= len-10; i++) {
            string str = s.substr(i, 10);
            int code = encode(str);
            if(map.find(code) != map.end()) {
                if(map[code] == 1) {
                    res.push_back(str);
                    map[code] = 2;
                }
            } else {
                map[code] = 1;
            }
        }
        return res;
    }
private:
    int encode(string str) {
        int code = 0;
        for(int i = 0; i < str.length(); i++) {
            char c = str[i];
            code <<= 2; // every 2 bits for a letter
            switch(c) {
                case 'A': code += 0; break;
                case 'C': code += 1; break;
                case 'G': code += 2; break;
                case 'T': code += 3; break;
            }
        }
        return code;
    }
};


/*
 * Hash Table + Bit Manipulation
 *
 *
 * Memo:
 * 0x7ffffff = 0b1111111111111111111111111111  (27 digits '1')
 * 7 = 0b111
 *
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() <= 10) return res;
        int mask = 0x7ffffff;
        unordered_map<int, int> m;
        int cur = 0, i = 0;
        while (i < 9) {
            cur = (cur << 3) | (s[i++] & 7);
        }
        while (i < s.size()) {
            cur = ((cur & mask) << 3) | (s[i++] & 7);
            if (m.find(cur) != m.end()) {
                if (m[cur] == 1) res.push_back(s.substr(i - 10, 10));
                ++m[cur]; 
            } else {
                m[cur] = 1;
            }
        }
        return res;
    }
};
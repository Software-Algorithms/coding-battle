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
/*
 * String, Design
 *
 */

// version 1:
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded;
        for(const auto &s : strs) {
            int len = s.size();
            encoded += to_string(len) + '/' + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0, n = s.size();
        while(i < n) {
            int start = i;
            while(i < n && s[i] != '/') i++; // find the position of '/'
            int len = stoi(s.substr(start, i-start));
            start = ++i;
            decoded.push_back(s.substr(start, len));
            i += len;
        }
        return decoded;
    }
};

// version 2:
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for (const string& s: strs) {
            int len = s.size();
            encoded += to_string(len) + "/" + s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int pos = 0;
        while (pos < s.size()) {
            int slashPos = s.find_first_of('/', pos);
            int len = stoi(s.substr(pos, slashPos - pos));
            pos = slashPos + 1;
            decoded.push_back(s.substr(pos, len));
            pos += len;
        }
        return decoded;
    }
};

// Conlcusion:




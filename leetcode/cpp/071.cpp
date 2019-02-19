/**
 * @Author: Harry Xu
 * @Date: 01/18/2018
 * @Description:
 *      Method: stack, two pointers
 *      Complexity: O(n)
 */
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            while (path[i] == '/' && i < path.size()) ++i;
            if (i == path.size()) break;
            int start = i;
            while (path[i] != '/' && i < path.size()) ++i;
            int end = i - 1;
            string s = path.substr(start, end - start + 1);
            if (s == "..") {
                if (!v.empty()) v.pop_back(); 
            } else if (s != ".") {
                v.push_back(s);
            }
        }
        if (v.empty()) return "/";
        string res;
        for (int i = 0; i < v.size(); ++i) {
            res += '/' + v[i];
        }
        return res;   
    }
};


/**
 * @Author: Harry Xu
 * @Date: 02/18/2019
 * @Description:
 *      Method: stack, two pointers
 *      Complexity: O(n)
 */
class Solution {
public:
    string simplifyPath(string path) {
        string canonical_path = "";
        vector<string> vec;
        int i = 0;
        while(i < path.size() && path[i] == '/') {
            int k = i+1;
            string cur = "";
            while(k < path.size() && path[k] != '/') {
                cur += path[k];
                k++;
            }
            if(cur == "..") {
                if(!vec.empty()) vec.pop_back();
            } else if(cur != "." && cur != "") {
                vec.push_back(cur);
            }
            i = k;
        }
           
        for(int i = 0; i < vec.size(); i++) {
            canonical_path += "/" + vec[i];
        }

        if(canonical_path == "") return "/";
        return canonical_path;
    }
};

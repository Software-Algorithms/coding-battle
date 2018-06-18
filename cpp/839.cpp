/*
 * String, Union Find
 *
 */

// version 1 (reference):
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        unordered_map<string,string> mapping;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            /*
            Updated on Jun 6th, there is an invalid test case, in the problem description, it says "a list of unique strings", but there are test cases with duplicate strings.
            In this case, the following line is added.
            */
            if (mapping.find(A[i]) != mapping.end()) continue;
            mapping[A[i]] = A[i];
            for (int j = 0; j < i; j++) {
                if (isSimilar(A[i], A[j]) && mapping[A[j]] != A[i]) {
                    string x = getRoot(A[j], mapping);
                    mapping[x] = A[i];
                }
            }
        }
        
        int result = 0;
        for (auto it = mapping.begin(); it != mapping.end(); it++) {
            if (it->first == it->second) result++;
        }
        return result;
    }
    
private:
    bool isSimilar(string &a, string &b) {
        int n = a.length(), counter = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) counter++;
        }
        return counter == 2;
    }
    
    string getRoot(string s, unordered_map<string,string> &mapping) {
        string temp = mapping[s];
        if (temp != s) return getRoot(temp, mapping);
        else return temp;
    }
};

// version 2 (own):
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        for (int i = 0; i < A.size(); i++) {
            father[A[i]] = A[i];
            for (int j = 0; j < i; j++) {
                if (isSimilar(A[i], A[j]) && father[A[j]] != A[i]) {
                    string x = find(A[j]);
                    father[x] = A[i];
                }
            }
        }
        
        int res = 0;
        for(auto it = father.begin(); it != father.end(); it++) {
            if(it->first == it->second) res++;
        }
        return res;       
    }
    
private:
    unordered_map<string, string> father;
    
    bool isSimilar(string &a, string &b) {
        int n = a.size(), diff = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) diff++;
        }
        return diff <= 2;
    }
    
    string find(string s) {
        if(father[s] == s) return s;
        return father[s] = find(father[s]);
    }
};

// Reference:
// Leetcode discuss: https://leetcode.com/problems/similar-string-groups/discuss/132375/C++-Union-Find-solution
// Leetcode article: https://leetcode.com/articles/similar-string-groups/




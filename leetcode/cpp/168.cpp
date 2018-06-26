class Solution {
public:
    string convertToTitle(int n) {
        int base = (int)'A';
        string title = "";
        
        while(n) {
            int count = (n-1)%26;
            title = (char)(base+count) + title;
            n = (n-1)/26;
        }
        
        return title;        
    }
};
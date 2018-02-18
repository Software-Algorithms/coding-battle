// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int res = 0;
        for(int i = 0, curr; i <= n/4 && curr != 0; i++){
            curr = read4(buf + res);
            res += curr;
        }
        return min(res, n);        
    }
};
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        
        string res;
        if( (numerator < 0) ^ (denominator < 0) ) res += "-";
        
        // get the absolute n and d
        long long n = numerator, d = denominator;
        n = abs(n);
        d = abs(d);
        
        res += to_string(n/d);
        long long r = n%d; // remainder
        if(r == 0) return res;
        
        // decimal part
        res += ".";
        unordered_map<int, int> map; // decimal digit appearance recording
        while(r) {
            // check if r repeats
            if( map.find(r) != map.end() ) {
                res.insert(map[r], 1, '(');
                res += ")";
                return res;
            }
            
            // record current r
            map[r] = res.size();
            r *= 10;
            res += to_string(r/d);
            r = r%d;
        }
        
        return res;
    }
};
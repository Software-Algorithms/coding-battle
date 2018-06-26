/*
 * Solution 1:
 *
 */
class Solution {
public:
    string nextClosestTime(string time) {
        string res =  time;
        set<char> s({time[0], time[1], time[3], time[4]});
        string str(s.begin(), s.end()); // ordered and unique
        
        // from lower to higher digit
        for(int i = res.size()-1; i >= 0; i--) {
            if(res[i] == ':') continue;
            int pos = str.find(res[i]);
            if(pos == str.size()-1) { // the biggest for the digit, go to next digit
                res[i] = str[0];
            } else {
                char next = str[pos+1];
                if(i == 4) {
                    res[i] = next;
                    return res;
                } else if (i == 3 && next < '6') {
                    res[i] = next;
                    return res;
                } else if (i == 1 && (res[0] < '2' || (res[0] == '2' && next < '4'))) {
                    res[i] = next;
                    return res;
                } else if (i == 0 && next < '3') {
                    res[i] = next;
                    return res;                    
                }
                res[i] = str[0];
            }
        }
        return res;  
    }
};

// Conclusion:
// 用数字集重新组合数字，是下一个更大的，麻烦的地方在于时间进制情况比较多。分情况讨论清楚就可以。
// 分钟低位：0-9；分钟高位：0-5；小时低位：0-9（小时高位<2）,0-3(小时高位为2)；小时高位：0-2.
//



/*
 * Solution 2:
 * Brute Force Search
 *
 */
class Solution {
public:
    string nextClosestTime(string time) {
        string res = "0000";
        vector<int> base({600, 60, 10, 1});
        
        int cur =  stoi(time.substr(0, 2))*60 + stoi(time.substr(3,2));

        // search from current tiime point by 1440 steps
        for(int i = 1; i < 1440; i++) {
            int next = (cur + i) % 1440;
            int j = 0;
            for(; j < 4; j++) {
                char tmp = '0' + next / base[j];
                if(time.find(tmp) == string::npos) break;
                res[j] = tmp;
                next = next % base[j];
            }
            if(j == 4) break;
        }
        return res.substr(0, 2) + ":" + res.substr(2);
    }
};

// Conclusion:
// Since there is 1440 minutes in a day, it is acceptable to traverse every time point
// and search for the next satisfying one.
//
// Reference:
// http://www.cnblogs.com/grandyang/p/7623614.html



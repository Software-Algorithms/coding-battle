/*
 * Two Pointers
 *
 */
class Solution {
public:
    string pushDominoes(string dominoes) {
        string res = dominoes;
        
        vector<pair<int, char>> pushes;
        for(int i = 0; i < dominoes.size(); i++) {
            if(dominoes[i] != '.') pushes.push_back({i, dominoes[i]});
        }
        if(pushes.empty()) return res;
        
        // deal with two sides
        if(pushes[0].second == 'L') {
            for(int i = 0; i < pushes[0].first; i++) {
                res[i] = 'L';
            }
        }
        if(pushes.back().second == 'R') {
            for(int i = pushes.back().first + 1; i < res.size(); i++) {
                res[i] = 'R';
            }
        }
        
        // two pointers
        int p = 0, q = pushes.size()-1;
        for(int i = p; i < q; i++) {
            if(pushes[i].second == pushes[i+1].second) {
                for(int j = pushes[i].first + 1; j < pushes[i+1].first; j++) {
                    res[j] = pushes[i].second;
                }
            } else if (pushes[i].second == 'R' && pushes[i+1].second == 'L') {
                int t1 = pushes[i].first + 1, t2 = pushes[i+1].first - 1;
                while(t1 < t2) {
                    res[t1] = 'R';
                    res[t2] = 'L';
                    t1++;
                    t2--;
                }
            }
        }
        
        return res;
    }
};

// Conclusion:
// 每个LR中间的interval求一遍，然后单独处理一下2边缘。
//
// Reference:
// https://blog.csdn.net/zjucor/article/details/80380899




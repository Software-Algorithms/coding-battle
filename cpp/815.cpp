/*
 * BFS
 *
 */
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        
        unordered_map<int, set<int>> m; // store stop -> route id set
        for (int i = 0; i < routes.size(); i++) {
            for (auto& stop : routes[i]) {
                m[stop].insert(i);
            }
        }
        
        queue<int> q; // store route id
        set<int> seen;
        for (auto& r : m[S]) {
            q.push(r);
            seen.insert(r);
        }
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto& r = q.front(); q.pop();
                for (auto& stop : routes[r]) {
                    if (stop == T) return level;
                    for (auto& nr : m[stop]) {
                        if (seen.count(nr) == 0) {
                            q.push(nr);
                            seen.insert(nr);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};



/*
 * BFS
 *
 */
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int goal = (1 << n) - 1;
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            q.push({i, 1 << i});
        }
        
        vector<vector<int>> visited(n, vector<int>(1 << n));
        
        int steps = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto t = q.front();
                q.pop();
                int node = t.first;
                int state = t.second;
                if(state == goal) return steps;
                if(visited[node][state]) continue;
                visited[node][state] = 1;
                for(int next : graph[node]) {
                  q.push({next, state | (1 << next)});
                }               
            }
            steps++;
        }
        
        return -1;
    }
};

// Conclusion:
// The State in "pair" format has two keys: head and cover;
// head means the position it is now at;
// cover means the positions it's already pass.
//
// Reference:
// Huahua: https://youtu.be/Vo3OEN2xgwk




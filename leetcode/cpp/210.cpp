/*
 * Graph, BFS
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> edges(numCourses);
        vector<int> d(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); ++ i) {
            edges[prerequisites[i].second].insert(prerequisites[i].first);
            d[prerequisites[i].first] ++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
            if (d[i] == 0)
                q.push(i);

        vector<int> order;
        while (!q.empty()) {
            int x = q.front(); q.pop();
            order.push_back(x);
            for(auto it = edges[x].begin(); it != edges[x].end(); ++ it) {
                -- d[*it];
                if (d[*it] == 0) {
                    q.push(*it);
                }
            }
        }
        if (order.size() == numCourses)
            return order;
        return vector<int>();

    }
};


/*
 * Topological Sort
 *
 * Reference: Huahua
 */
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(const auto& p : prerequisites)
            graph[p.second].push_back(p.first);

        // states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> v(numCourses, 0);
        vector<int> ans;

        for (int i = 0; i < numCourses; ++i)
            if (dfs(i, graph, v, ans)) return {};

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
private:
    bool dfs(int cur, vector<vector<int>>& graph, vector<int>& v, vector<int>& ans) {
        if (v[cur] == 1) return true;
        if (v[cur] == 2) return false;

        v[cur] = 1;

        for (const int t : graph[cur])
            if (dfs(t, graph, v, ans)) return true;

        v[cur] = 2;
        ans.push_back(cur);

        return false;
    }
};
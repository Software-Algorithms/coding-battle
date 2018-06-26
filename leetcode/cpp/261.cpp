/*
 * BFS, Graph
 *
 */

// version 1:
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        unordered_set<int> s{{0}};
        queue<int> q{{0}};
        for (auto a : edges) {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (auto a : g[t]) {
                if (s.count(a)) return false;
                s.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return s.size() == n;
    }
};

// version 2:
class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>> neighbors(n, unordered_set<int>());
        unordered_set<int> visited;
        for(auto e : edges) {
            neighbors[e.first].insert(e.second);
            neighbors[e.second].insert(e.first);
        }
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            if(visited.count(t)) return false; // cycle detected!
            visited.insert(t);
            for(int x : neighbors[t]) {
                q.push(x);
                neighbors[x].erase(t); // node in one edge counts once
            }
        }
        
        return visited.size() == n; // connected graph <-- tree        
    }
};

// version 2.5: lintcode version:
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        vector<unordered_set<int>> neighbors(n, unordered_set<int>());
        unordered_set<int> visited;
        for(auto edge : edges) {
            neighbors[edge[0]].insert(edge[1]);
            neighbors[edge[1]].insert(edge[0]);
        }
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()) {
            int len = q.size();
            for(int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                if(visited.count(t)) return false; // cycle detected!
                visited.insert(t);
                for(int x : neighbors[t]) {
                    q.push(x);
                    neighbors[x].erase(t); // node in one edge counts once
                }
            }
        }
        
        return visited.size() == n; // connected graph <-- tree
    }
};

// Conclusion:
// 用queue来辅助遍历;
// 用一维unorded_set来标记节点是否访问过，如果遍历到一个节点，在set中没有，则加入set，如果已经存在，则返回false;
// 还有就是在遍历邻接链表的时候，遍历完成后需要将节点删掉，避免同一个边的两个节点重复访问。





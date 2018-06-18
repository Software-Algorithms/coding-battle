/*
 * Solution 1:
 * DFS
 *
 */
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = 0;
        vector<vector<int>> vertices(n); // v --> all other vertices that connected to v
        vector<bool> visited(n, false);
        
        for(auto &v : edges) {
            vertices[v.first].push_back(v.second);
            vertices[v.second].push_back(v.first);
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                dfs(vertices, visited, i);
            }
        }
        
        return res;
    }
    
    void dfs(vector<vector<int> > &vertices, vector<bool> &visited, int i) {
        if(visited[i]) return;
        visited[i] = true;
        for(int j = 0; j < vertices[i].size(); ++j) {
            dfs(vertices, visited, vertices[i][j]);
        }
    }
};

// Conclusion:
// 一种解法是利用DFS来做，思路是给每个节点都有个flag标记其是否被访问过，对于一个未访问过的节点，
// 我们将结果自增1，因为这肯定是一个新的连通区域，然后我们通过邻接链表来遍历与其相邻的节点，并将
// 他们都标记成已访问过，遍历完所有的连通节点后我们继续寻找下一个未访问过的节点，以此类推直至所有
// 的节点都被访问过了，那么此时我们也就求出来了连通区域的个数。




/*
 * Solution 2:
 * Union Find
 *
 */
class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (auto a : edges) {
            int x = find(root, a.first), y = find(root, a.second);
            if (x != y) {
                --res;
                root[y] = x;
            }
        }
        return res;
    }
    
    int find(vector<int> &root, int i) {
        while (root[i] != i) i = root[i];
        return i;
    }
};

// Conclusion:
// 其实就是unionfind的实现。
//
// Reference:
// Grandyang: http://www.cnblogs.com/grandyang/p/5166356.html
//




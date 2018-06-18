/*
 * Solution 1:
 * DFS
 *
 */
class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        int res = 0;
        vector<vector<int> > g(n);
        vector<bool> v(n, false);
        for (auto a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                ++res;
                dfs(g, v, i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int> > &g, vector<bool> &v, int i) {
        if (v[i]) return;
        v[i] = true;
        for (int j = 0; j < g[i].size(); ++j) {
            dfs(g, v, g[i][j]);
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




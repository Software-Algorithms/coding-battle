/*
 * DP
 *
 */

// version 1:
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<unordered_set<int>> tree(N);
        vector<int> res(N, 0);
        vector<int> count(N, 0);
        if (N == 1) return res;
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        unordered_set<int> seen1, seen2;
        dfs(0, seen1);
        dfs2(0, seen2N);
        return res;

    }

    void dfs(int root, unordered_set<int>& seen) {
        seen.insert(root);
        for (auto i : tree[root]) {
            if (seen.count(i) == 0) {
                dfs(i, seen);
                count[root] += count[i];
                res[root] += res[i] + count[i];
            }
        }
        count[root] += 1;
    }

    void dfs2(int root, unordered_set<int>& seen, int N) {
        seen.insert(root);
        for (auto i : tree[root]) {
            if (seen.count(i) == 0) {
                res[i] = res[root] - count[i] + N - count[i];
                dfs2(i, seen, N);
            }
        }
    }

private:
	vector<unordered_set<int>> tree;
	vector<int> res, count;
};

// version 2:
class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        ans.resize(N);
        count = vector<int>(N, 1);

        for (int i = 0; i < N; ++i)
            graph.push_back(unordered_set<int>());
        for (auto edge: edges) {
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }
        dfs(0, -1);
        dfs2(0, -1, N);
        return ans;
    }

    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent, const int& N) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + N - count[child];
                dfs2(child, node, N);
            }
        }
    }
    
private:
    vector<int> ans, count;
    vector<unordered_set<int>> graph;
};

// Conclusion:
//
// Reference:
// Leetcode Discussion: https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C++JavaPython-Pre-order-and-Post-order-DFS-O(N)
// Leetcode Article: https://leetcode.com/articles/sum-of-distances-in-tree/





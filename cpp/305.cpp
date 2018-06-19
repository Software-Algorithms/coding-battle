/*
 * Union Find
 *
 */

// version 1:
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        int cnt = 0;
        vector<int> roots(m * n, -1);
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        for (auto a : positions) {
            int id = n * a.first + a.second;
            roots[id] = id;
            ++cnt;
            for (auto dir : dirs) {
                int x = a.first + dir[0], y = a.second + dir[1], cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1) continue;
                int p = findRoot(roots, cur_id), q = findRoot(roots, id);
                if (p != q) {
                    roots[p] = q;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    int findRoot(vector<int>& roots, int id) {
        return (id == roots[id]) ? id : findRoot(roots, roots[id]);
    }
};

// version 2:
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        int cnt = 0;
        
        roots.resize(m*n);
        for(int i = 0; i < m*n; i++) roots[i] = -1;
        
        vector<vector<int>> dirs({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
        
        for(auto a : positions) {
            int id = n * a.first + a.second;
            cnt++;
            roots[id] = id;
            for(auto dir : dirs) {
                int x = a.first + dir[0], y = a.second + dir[1], cur_id = x * n + y;
                if(x < 0 || x >= m || y < 0 || y >= n || roots[cur_id] == -1) continue;
                int p = findRoot(cur_id), q = findRoot(id);
                if(p != q) {
                    roots[p] = q;
                    cnt--;
                }
            }
            res.push_back(cnt);
        }
        
        return res;
    }

private:
    vector<int> roots; // label the islane
    
    int findRoot(int id) {
        if(roots[id] == id) return id;
        return roots[id] = findRoot(roots[id]);
    }
};

// Conclusion:
// 为了解决这种陆地之间会合并的情况，最好能够将每个陆地都标记出其属于哪个岛屿，这样就会方便我们统计岛屿个数。
// 这种群组类问题，很适合使用联合查找 Union Find 来做，又叫并查集 Disjoint Set，LeetCode中使用这种解法
// 的题目还不少呢，比如Friend Circles，Graph Valid Tree，Redundant Connection II 等等。
//
// Reference:
// http://www.cnblogs.com/grandyang/p/5190419.html
//
// Union Find
// A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
// Find: Determine which subset a particular element is in. This can be used for determining if two ele
//       ments are in the same subset.
// Union: Join two subsets into a single subset.




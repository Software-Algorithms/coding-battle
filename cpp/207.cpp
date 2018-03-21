/**
 * Graph, BFS
 *
 * Reference: cnblogs.com/grandyang
 *
 * BFS的解法:
 * 我们定义二维数组graph来表示这个有向图，一位数组in来表示每个顶点的入度。
 * 我们开始先根据输入来建立这个有向图，并将入度数组也初始化好。然后我们定义
 * 一个queue变量，将所有入度为0的点放入队列中，然后开始遍历队列，从graph里
 * 遍历其连接的点，每到达一个新节点，将其入度减一，如果此时该点入度为0，则放
 * 入队列末尾。直到遍历完队列中所有的值，若此时还有节点的入度不为0，则说明环
 * 存在，返回false，反之则返回true。
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        // initialize
        vector<vector<bool>> map(numCourses, vector<bool>(numCourses, false));
        vector<int> ind(numCourses, 0);

        // construct map & indegree matrix
        for(auto a : prerequisites) {
            if(map[a.first][a.second] == false) {
                map[a.first][a.second] = true;
                ind[a.first]++;
            }
        }

        // BFS
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(ind[i] == 0) q.push(i);
        }

        int count = 0;
        while(!q.empty()) {
            int temp = q.front();
            q.pop();
            count++;
            for(int i = 0; i < numCourses; i++) {
                if(map[i][temp] == true) {
                    ind[i]--;
                    if(ind[i] == 0) q.push(i);
                }
            }
        }

        return count < numCourses ? false : true;
    }
};


/*
 * Graph, Topological Sort, DFS
 *
 * Ref: Huahua
 */
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph_ = vector<vector<int>>(numCourses);

        for(const auto& p : prerequisites)
            graph_[p.first].push_back(p.second);

        // states: 0 = unkonwn, 1 == visiting, 2 = visited
        vector<int> v(numCourses, 0);

        for(int i = 0; i < numCourses; ++i)
            if(dfs(i, v)) return false;

        return true;
    }

private:
    vector<vector<int>> graph_;
    bool dfs(int cur, vector<int>& v) {
        if(v[cur] == 1) return true;
        if(v[cur] == 2) return false;

        v[cur] = 1;

        for(const int t : graph_[cur])
            if(dfs(t, v)) return true;

        v[cur] = 2;

        return false;
    }
};
//
// https://www.lintcode.com/problem/topological-sorting/description
// https://www.jiuzhang.com/solutions/topological-sorting

/*
 * Graph, BFS, TopoSort
 *
 */

// version 1:
class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        vector<DirectedGraphNode*> res;
        unordered_map<DirectedGraphNode*, int> m;
        
        for (DirectedGraphNode* node : graph) {
            for (DirectedGraphNode* neighbor : node->neighbors) {
                m[neighbor]++;
            }
        }
        
        queue<DirectedGraphNode*> q;
        for (DirectedGraphNode* node : graph) {
            if (!m.count(node)) {
                q.push(node);
                res.push_back(node);
            }
        }
        
        while (!q.empty()) {
            DirectedGraphNode* node = q.front();
            q.pop();
            for (DirectedGraphNode* n : node->neighbors) {
                m[n]--;
                if (m[n] == 0) {
                    res.push_back(n);
                    q.push(n);
                }
            }
        }
        
        return res;
    }
};

// version 2:
class Solution {
public:
    /*
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        // write your code here
        vector<DirectedGraphNode*> res;
        unordered_map<DirectedGraphNode*, int> indegrees;
        
        // compute indegree: node --> indegree
        for (DirectedGraphNode* node : graph) {
            for (DirectedGraphNode* neighbor : node->neighbors) {
                indegrees[neighbor]++;
            }
        }
        
        // start from the node with indegree 0
        queue<DirectedGraphNode*> q;
        for (DirectedGraphNode* node : graph) {
            if (!indegrees.count(node)) {
                q.push(node);
            }
        }
        
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            for (auto nb : t->neighbors) {
                indegrees[nb]--;
                if (indegrees[nb] == 0) {
                    q.push(nb);
                }
            }
        }
        
        return res;
    }
};

// Conclusion:
// Kahn算法:
// 该算法的实现十分直观，关键在于需要维护一个入度为0的顶点的集合：
// 1)
// 每次从该集合中取出(没有特殊的取出规则，随机取出也行，使用队列/栈也行，下同)一个顶点，将该顶点放入保存结果的List中。
// 2)
// 紧接着循环遍历由该顶点引出的所有边，从图中移除这条边，同时获取该边的另外一个顶点，如果该顶点的入度在减去本条边之后为0，
// 那么也将这个顶点放到入度为0的集合中。然后继续从集合中取出一个顶点…………
// 3)
// 当集合为空之后，检查图中是否还存在任何边，如果存在的话，说明图中至少存在一条环路。不存在的话则返回结果List，此List中的
// 顺序就是对图进行拓扑排序的结果。
//
// Reference:
// https://blog.csdn.net/dm_vincent/article/details/7714519





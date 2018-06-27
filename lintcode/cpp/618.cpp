// Lintcode 618. Search Graph Nodes
// https://www.lintcode.com/problem/search-graph-nodes/description
// https://www.jiuzhang.com/solutions/search-graph-nodes

/*
 * Graph, BFS
 *
 */
class Solution {
public:
    /*
     * @param graph: a list of Undirected graph node
     * @param values: a hash mapping, <UndirectedGraphNode, (int)value>
     * @param node: an Undirected graph node
     * @param target: An integer
     * @return: a node
     */
     UndirectedGraphNode* searchNode(vector<UndirectedGraphNode*>& graph,
                                    map<UndirectedGraphNode*, int>& values,
                                    UndirectedGraphNode* node,
                                    int target) {
        // write your code here
        unordered_set<UndirectedGraphNode*> visited;
        
        queue<UndirectedGraphNode*> q;
        q.push(node);
        
        while(!q.empty()) {
            auto t = q.front();
            q.pop();
            if(values[t] == target) return t;
            if(visited.count(t)) continue;
            visited.insert(t);
            for(auto nb : t->neighbors) {
                q.push(nb);
            }
        }
        return NULL;
    }
};

// Conclusion:
// BFS:
// 确定起始点；
// 是否需要记录层级数；
// 图需要一个记忆矩阵避免回环访问；
// 结束条件。






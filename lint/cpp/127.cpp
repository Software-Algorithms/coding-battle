//
// https://www.lintcode.com/problem/topological-sorting/description
// https://www.jiuzhang.com/solutions/topological-sorting

/*
 * Graph, BFS, TopoSort
 *
 */
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

//
//





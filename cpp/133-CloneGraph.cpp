/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    map<int, UndirectedGraphNode*> visited;
    
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        
        if(visited.find(node->label) == visited.end()) {
            UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
            visited[node->label] = copy;
            for(int i = 0; i < node->neighbors.size(); i++) {
                copy->neighbors.push_back(cloneGraph(node->neighbors[i]));
            }
        }
        
        return visited[node->label];        
    }
};
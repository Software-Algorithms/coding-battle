/*
 * Graph, Recursion
 *
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





/*
 * BFS, Graph
 *
 */

// lintcode version:
class Solution {
public:
    /*
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node) {
        // write your code here
        if (!node) return NULL;

        UndirectedGraphNode *p1 = node;
        UndirectedGraphNode *p2 = new UndirectedGraphNode(node->label);
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;
        m[p1] = p2;
        
        queue<UndirectedGraphNode*> q;        
        q.push(node);
        
        while(!q.empty()) {
            p1 = q.front();
            p2 = m[p1];
            q.pop();
            for(int i = 0; i < p1->neighbors.size(); i++) {
                UndirectedGraphNode *nb = p1->neighbors[i];
                if(m.count(nb)) {
                    p2->neighbors.push_back(m[nb]);
                } else {
                    UndirectedGraphNode *copy = new UndirectedGraphNode(nb->label);
                    p2->neighbors.push_back(copy);
                    m[nb] = copy;
                    q.push(nb);
                }
            }
        }
        
        return m[node];
    }
};

// Conclusion:
// unordered_map 在这里起到记忆的作用，避免重复。






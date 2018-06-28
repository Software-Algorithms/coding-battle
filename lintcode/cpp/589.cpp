// 589. Connecting Graph
// Problem description: http://www.lintcode.com/problem/connecting-graph/
// Problem solution: https://www.jiuzhang.com/solutions/connecting-graph

/*
 * Union Find, Design
 *
 */
class ConnectingGraph {
public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        father.resize(n+1);
        for(int i = 0; i <= n; i++) {
            father[i] = i;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int x = find(a), y = find(b);
        if(x != y) {
            father[a] = b;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        return find(a) == find(b);
    }
    
private:
    vector<int> father;
    
    int find(int x) {
        if(father[x] == x) return x;
        return father[x] = find(father[x]);
    }
};

// Conclusion:
// Union Find Concept.





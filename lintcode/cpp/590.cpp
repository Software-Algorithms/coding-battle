// 590. Connecting Graph II
// Problem description: http://www.lintcode.com/problem/connecting-graph-ii/
// Problem solution: https://www.jiuzhang.com/solutions/connecting-graph-ii

/*
 * Union Find, Design
 *
 */
class ConnectingGraph2 {
public:
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        // do intialization if necessary
        father.resize(n + 1);
        capacity.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            father[i] = 0;
            capacity[i] = 1;
        }
    }

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int a, int b) {
        // write your code here
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            father[root_a] = root_b;
            capacity[root_b] += capacity[root_a];
        }        
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here
        int root_a = find(a);
        return capacity[root_a];
    }
    
private:
    vector<int> father;
    vector<int> capacity;

    int find(int x) {
        if (father[x] == 0)
            return x;
        return father[x] = find(father[x]);    
    }
};

// Conclusion:
// Union Find Concept.





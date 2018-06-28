// 591. Connecting Graph III
// Problem description: http://www.lintcode.com/problem/connecting-graph-iii/
// Problem solution: https://www.jiuzhang.com/solutions/connecting-graph-iii

/*
 * Union Find, Design
 *
 */
class ConnectingGraph3 {
public:
    /*
    * @param n: An integer
    */ConnectingGraph3(int n) {
        // do intialization if necessary
        father.resize(n + 1);
        count = n;
        for (int i = 1; i <= n; ++i) {
            father[i] = 0;
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
            count --;
        }
    }

    /*
     * @return: An integer
     */
    int query() {
        // write your code here
        return count;
    }
    
private:
    vector<int> father;
    int count;

    int find(int x) {
        if (father[x] == 0)
            return x;
        return father[x] = find(father[x]);    
    }
};

// Conclusion:
// Union Find Concept.





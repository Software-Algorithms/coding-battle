// Lintcode 543. Kth Largest in N Arrays
// Problem description: https://www.lintcode.com/problem/kth-largest-in-n-arrays/description
// Problem solution: 

/*
 * Heap (priority_queue)
 *
 */

struct Node {
    int x, y, val;
    Node (int _x, int _y, int _val) : x(_x), y(_y), val(_val) {}
    bool operator < (const Node& rhs) const {
        return val < rhs.val;
    }
};

class Solution {
public:
    /**
     * @param arrays: a list of array
     * @param k: An integer
     * @return: an integer, K-th largest element in N arrays
     */
    int KthInArrays(vector<vector<int>> &arrays, int k) {
        // write your code here
        if (arrays.empty()) {
            return -1;
        }
        
        int n = arrays.size();
        
        for(int i = 0; i < n; i++) {
            sort(arrays[i].begin(), arrays[i].end());
        }
        
        priority_queue<Node> q;
        for (int i = 0; i < n; i++) {
            int m = arrays[i].size();
            if(m > 0) q.push(Node(i, m-1, arrays[i][m-1]));
        }
        
        while(k) {
            auto t = q.top(); q.pop();
            if(k == 1) return t.val;
            if(t.y > 0) {
                int x = t.x, y = t.y-1, val = arrays[x][y];
                q.push(Node(x, y, val));
            }
            k--;
        }
        
        return -1;

    }
};

// Conclusion:
// 集合中找最大或最小想到用堆Heap(priority_queue)。
//
// 几个易错的地方：
// 1. 空数组的情况，其中没有元素可以push进priority_queue中，在初始化的时候，要把空数组排除，不然会造成非法访问；
// 2. 用while循环，作用是进行k次pop操作，小心使用是--k, k--, 这里使用的是最安全的分开处理；
// 3. 紧接着pop操作后检查pop出去的值作为 kth largest .





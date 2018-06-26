// Lintcode 465. Kth Smallest Sum In Two Sorted Arrays
// Problem description: https://www.lintcode.com/problem/kth-smallest-sum-in-two-sorted-arrays/description
// Problem solution: https://www.jiuzhang.com/solutions/kth-smallest-sum-in-two-sorted-arrays/#tag-highlight-lang-cpp

/*
 * Heap (priority_queue)
 *
 */

class Node {
public:
    int value, x, y;
    Node(int _v, int _x, int _y) {
        value = _v;
        x = _x;
        y = _y;
    }
    bool operator < (const Node& obj) const {
        return value > obj.value;
    }
};

class Solution {
public:
    /**
     * @param A an integer arrays sorted in ascending order
     * @param B an integer arrays sorted in ascending order
     * @param k an integer
     * @return an integer
     */
    int kthSmallestSum(vector<int>& A, vector<int>& B, int k) {
        // Write your code here
        int n = A.size();
        int m = B.size();
        priority_queue<Node> q;
        q.push(Node(A[0] + B[0], 0, 0));
        map<int, bool> mp;
        int ans = -1;
        mp[0] = true;
        for (int i = 0; i < k; ++i) {
            Node tmp = q.top(); q.pop();
            ans = tmp.value;
            int x = tmp.x, y = tmp.y;
            if (x + 1 < n) {
                int data = (x + 1) * m + y;
                if (mp.find(data) == mp.end()) {
                    mp[data] = true;
                    q.push(Node(A[x + 1] + B[y], x + 1, y));
                }
            }
            if (y + 1 < m) {
                int data = x * m + y + 1;
                if (mp.find(data) == mp.end()) {
                    mp[data] = true;
                    q.push(Node(A[x] + B[y + 1], x, y + 1));
                }
            }
        }
        return ans;
    }
};

// Conclusion:
// 此题乍看似乎没有很好的思路，其实稍加转化就变成了熟悉的问题：Kth Smallest Number in Sorted Matrix.
//
// 两个array中间分别取一个数相加得到一个sum，其实可以想象一个Matrix，里面元素的坐标就是分别在两个Array中的下标index，
// 而元素的值则是sum的值。那么很显然，因为两个array都是排序过的，那么对于这个想象中的matrix中的每一行每一列来说，都是
// 排好序的。
//
// 比如对于[1, 7, 11] and [2, 4, 6].
// M   1,  7, 11
// 2,  3,  9, 13
// 4,  5, 11, 15
// 6,  7, 13, 17
//
// 接下来就可以利用PriorityQueue构造Min Heap来解决了。
//
// 这道题还需要一个visited矩阵避免重复。一开始想不明白为什么只有向右向下的移动还会有重复访问，只要稍稍画个图就不难理解，
// 比如一个 2x2 矩阵，右下角的位置有可能从上面的元素过来也有可能从左边过来。这时就要避免push两次同样位置的值。
//
// Reference:
// https://aaronice.gitbooks.io/lintcode/content/data_structure/kth_smallest_sum_in_two_sorted_arrays.html





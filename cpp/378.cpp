/*
 * Heap (priority queue)
 *
 */
struct Node {
	int val, i, j;
	Node(int i, int j, int val) :i(i), j(j), val(val) {}
	bool operator < (const Node & x)const {
		return val > x.val;
	}
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<Node> q;
		int n = matrix.size();
		q.push(Node(0, 0, matrix[0][0]));
		while (--k > 0) {
			Node  x = q.top(); q.pop();
			if (x.i == 0 && x.j + 1 < n) q.push(Node(x.i, x.j + 1, matrix[x.i][x.j + 1]));
			if (x.i + 1 < n) q.push(Node(x.i + 1, x.j, matrix[x.i + 1][x.j]));
		}
		return q.top().val;        
    }
};

// Conclusion:
// 





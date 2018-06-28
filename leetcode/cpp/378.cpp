/*
 * Heap (priority queue)
 *
 */

// version 1:
struct Node {
	int val, i, j;
	Node(int i, int j, int val) :i(i), j(j), val(val) {}
	bool operator < (const Node & rhs) const {
		return val > rhs.val;
	}
};

class Solution {
public:
	int kthSmallest(vector<vector<int>> &matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		vector<vector<bool>> visited(m, vector<bool>(n, false));
		priority_queue<Node> q;
		q.push(Node(0, 0, matrix[0][0]));
		int dirs[2][2] = {{1, 0}, {0, 1}};
		while (--k > 0) {
			Node t = q.top(); q.pop();
			for(auto dir : dirs ) {
				int x = t.i + dir[0], y = t.j + dir[1];
				if(x >= m || y >= n || visited[x][y]) continue;
				q.push(Node(x, y, matrix[x][y]));
				visited[x][y] = true;
			}
		}
		return q.top().val;         
	}
};

// Conclusion:
// 有点像低配的BFS。


// version 2:
struct Node {
	int val, i, j;
	Node(int i, int j, int val) :i(i), j(j), val(val) {}
	bool operator < (const Node & rhs) const {
		return val > rhs.val;
	}
};

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int m = matrix.size(), n = matrix[0].size();
		priority_queue<Node> q;
		q.push(Node(0, 0, matrix[0][0]));
		while (--k > 0) {
			Node  x = q.top(); q.pop();
			if (x.i == 0 && x.j + 1 < n) q.push(Node(x.i, x.j + 1, matrix[x.i][x.j + 1]));
			if (x.i + 1 < m) q.push(Node(x.i + 1, x.j, matrix[x.i + 1][x.j]));
		}
		return q.top().val;        
	}
};

// Conclusion:
// 这里 x.i == 0 的作用就是避免重复，只在第一行往两个方向（右移和下移）遍历，从第二行开始，延伸的方向仅限向下，这样可以避免重复访问。
// 更具体来说，一个被访问的元素，它的上一处位置，可能是左边，也可能是上边，除了第一行和第一列，如果不加限制，一定会造成重复。
// 一般来说，可以用一个 记忆矩阵 visited 来指示元素是否被访问过，来避免重复，这里更加巧妙，因为两个方向的移动是等效的，所以限制任意其中
// 一条搜索方向就可以了。





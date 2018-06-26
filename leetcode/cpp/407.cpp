/*
 * Heap + BFS
 *
 */

// version 1:
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size(), res = 0, mx = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    q.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }
        while (!q.empty()) {
            auto t = q.top(); q.pop();
            int h = t.first, r = t.second / n, c = t.second % n;
            mx = max(mx, h);
            for (int i = 0; i < dir.size(); ++i) {
                int x = r + dir[i][0], y = c + dir[i][1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                visited[x][y] = true;
                if (heightMap[x][y] < mx) res += mx - heightMap[x][y];
                q.push({heightMap[x][y], x * n + y});
            }
        }
        return res;
    }
};

// version 2:
struct Cell {
    int x, y, h;
    Cell(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
    bool operator<(const Cell& rhs) const {
        return this->h > rhs.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.empty() || heightMap[0].empty()) return 0;
        
        int res = 0;
        int m = heightMap.size(), n = heightMap[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        // priority queue
        // put all boarders into the queue
        priority_queue<Cell> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || i == m-1 || j == 0 || j == n-1) {
                    q.push(Cell(i, j, heightMap[i][j]));
                    visited[i][j] = true;
                }
            }
        }
        
        // maintain a water max height as the upper bound
        int mx = INT_MIN;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // bfs from the top of the queue
        while(!q.empty()) {
            Cell t = q.top();
            q.pop();
            mx = max(mx, t.h);
            for(int k = 0; k < 4; k++) {
                int x = t.x + dirs[k][0], y = t.y + dirs[k][1];
                if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) continue;
                visited[x][y] = true;
                if(heightMap[x][y] < mx) {
                    res += mx - heightMap[x][y];
                }
                q.push(Cell(x, y, heightMap[x][y]));
            }
        }
        
        return res;
    }
};
};

/*****
为什么
  if (heightMap[x][y] < mx) res += mx - heightMap[x][y];
这一行 work ?

这一行的条件是访问到了某一个没visit的块高度为 heightMap[x][y]，并且此时的全局水位mx比之高，结果是此块能积水 mx - heightMap[x][y]

1. 为什么能积水，即当前这一块不会通过比自己更矮的块流出去：因为遍历开始讲边缘的块都放入了优先队列，因此如果对于当前块，存在一条通向边缘的
路径使得路径上的点高度都<当前块高度，那一定在水位上升到比它高之前被遍历到，与条件冲突

2. 为什么积水不会 < mx - heightMap[x][y]: 即为什么不存在一个高度 h<mx, h>heightMap[x][y]，使得在 x,y处 >h 的水会流出。如果存在，
那这个h所在块将存在一条到边缘的路径使得路径上的所有块高度都<h（否则无法流出）。根据优先队列以及BFS，h一定可以在水位上升到>h的高度之前被访
问，使得访问到h的时候水位也为h。同样，也存在一条从h所在块到当前块的路径使得路径上所有块高度都<h且>heightMap[x][y]，使得水能够从h块流出。
那么在水位为h的时候，当前块就会被访问到，当水位上升至mx>h时，当前块已经访问了，与条件冲突

3. 为什么积水不会 > mx - heightMap[x][y]，即设当前水位mx=h1为围绕在当前块周围的高度，为什么不会在当前mx对应边缘的外层存在一层更高h2
的边缘，使的在当前块上能积水h2>h1=mx：如果存在这种情况，那么访问到h2边缘层的时候，mx已经上升到h2的高度，也就是访问到当前块时，mx=h2>h1，
与条件冲突。
*/

// Conclusion:
// Trapping water I can be solved by Two Pointers but not this one.
// From boarder to go insider, we check each cell with its around. So BFS is a good method here.
//
// 怎么想到用堆（Heap）? 或者说，堆（Heap）在这里的作用是什么？
// 答：这里我们需要从外向里遍历，得到外层或外圈的最低值，就用一个最小堆（Heap）去维护，堆顶就是最低值。
//
// std::priority_queue
// template<
//     class T,
//     class Container = std::vector<T>,
//     class Compare = std::less<typename Container::value_type>
// > class priority_queue;
//
// A priority queue is a container adaptor that provides constant time lookup of
// the largest (by default) element, at the expense of logarithmic insertion and
// extraction.
// A user-provided Compare can be supplied to change the ordering,
// e.g. using std::greater<T> would cause the smallest element to appear as the top().
// - similar to managing a heap in some random access container
//
// Reference:
// http://www.cnblogs.com/grandyang/p/5928987.html
// https://leetcode.com/problems/trapping-rain-water-ii/discuss/89468/(C++)-The-priority-queue-sol-works-for-both-trap-water-I-and-II
//
// Visualization:
// https://youtu.be/cJayBq38VYw




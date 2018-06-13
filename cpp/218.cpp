/*
 * Solution 1:
 * Sweep Line + Heap
 *
 */

// version 1: priority_queue
class Solution {
private:
    enum NODE_TYPE {LEFT, RIGHT};
    struct node {
        int x, y;
        NODE_TYPE type;
        node(int _x, int _y, NODE_TYPE _type) : x(_x), y(_y), type(_type) {}
    };
    
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<node> height;
        for (auto &b : buildings) {
            height.push_back(node(b[0], b[2], LEFT));
            height.push_back(node(b[1], b[2], RIGHT));
        }
        sort(height.begin(), height.end(), [](const node &a, const node &b) {
            if (a.x != b.x) return a.x < b.x;
            else if (a.type == LEFT && b.type == LEFT) return a.y > b.y;
            else if (a.type == RIGHT && b.type == RIGHT) return a.y < b.y;
            else return a.type == LEFT;
        });
        
        priority_queue<int> heap;
        unordered_map<int, int> mp;
        heap.push(0);
        vector<pair<int, int>> res;
        int pre = 0, cur = 0;
        for (auto &h : height) {
            if (h.type == LEFT) {
                heap.push(h.y);
            } else {
                ++mp[h.y];
                while (!heap.empty() && mp[heap.top()] > 0) {
                    --mp[heap.top()];
                    heap.pop();
                }
            }   
            cur = heap.top();
            if (cur != pre) {
                res.push_back({h.x, cur});
                pre = cur;
            }
        }
        return res;
    }
};

// Conclusion:
// Use priority_queue as Heap.
// 分别将每个线段的左边节点与右边节点存到新的vector height中，根据x坐标值排序，然后遍历求拐点。
// 求拐点的时候用一个最大化heap来保存当前的楼顶高度，遇到左边节点，就在heap中插入高度信息，遇到
// 右边节点就从heap中删除高度。分别用pre与cur来表示之前的高度与当前的高度，当cur != pre的时候
// 说明出现了拐点。在从heap中删除元素时要注意，我使用priority_queue来实现，priority_queue并
// 不提供删除的操作，所以又用了别外一个unordered_map来标记要删除的元素。在从heap中pop的时候先
// 看有没有被标记过，如果标记过，就一直pop直到空或都找到没被标记过的值。别外在排序的时候要注意，
// 如果两个节点的x坐标相同，我们就要考虑节点的其它属性来排序以避免出现冗余的答案。且体的规则就是
// 如果都是左节点，就按y坐标从大到小排，如果都是右节点，按y坐标从小到大排，一个左节点一个右节点，
// 就让左节点在前。
//
// priority_queue
//
//

// version 2: multiset (simpliest)
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);
            else m.erase(m.find(a.second));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};

// Conclusion:
// Use multiset as heap.
//
// multiset
//
//

// Reference:
// http://www.cnblogs.com/grandyang/p/4534586.html
// http://www.cnblogs.com/easonliu/p/4531020.html


// version 3: self defined maxHeap
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        // events,   x,   h,   id,  type (1=entering, -1=leaving)
        vector<Event> events;
        
        int id = 0;
        for (const auto& b : buildings) {
            events.push_back(Event{id, b[0], b[2], 1});
            events.push_back(Event{id, b[1], b[2], -1});
            ++id;
        }
        
        // Sort events by x
        sort(events.begin(), events.end());
        
        // Init the heap
        MaxHeap heap(buildings.size());
        
        vector<pair<int, int>> ans;
        // Process all the events
        for (const auto& event: events) {            
            int x = event.x;
            int h = event.h;
            int id = event.id;
            int type = event.type;            
            
            if (type == 1) {
                if (h > heap.Max()) 
                    ans.emplace_back(x, h);
                heap.Add(h, id);
            } else {
                heap.Remove(id);
                if (h > heap.Max())
                    ans.emplace_back(x, heap.Max());
            }            
        }
        
        return ans;
    }
private:
    struct Event {
        int id;
        int x;       
        int h;
        int type;
        
        // sort by x+, type-, h, 
        bool operator<(const Event& e) const {
            if (x == e.x)                
                // Entering event h from large to small
                // Leaving event h from small to large
                return type * h > e.type * e.h;
            
            return x < e.x;
        }
    };
    
    class MaxHeap {
    public:
        MaxHeap(int max_items): 
            idx_(max_items, -1), vals_(max_items), size_(0) {}
        
        // Add an item into the heap. O(log(n))
        void Add(int key, int id) {
            idx_[id] = size_;
            vals_[size_] = {key, id};
            ++size_;
            HeapifyUp(idx_[id]);
        }
        
        // Remove an item. O(log(n))
        void Remove(int id) {
            int idx_to_evict = idx_[id];
            // swap with the last element
            SwapNode(idx_to_evict, size_ - 1);
            --size_;
            HeapifyDown(idx_to_evict);
            HeapifyDown(idx_to_evict);
        }
        
        bool Empty() const {
            return size_ == 0;
        }
        
        // Return the max of heap
        int Max() const {
            return Empty() ? 0 : vals_.front().first;
        }
    private:
        void SwapNode(int i, int j) {
            if (i == j) return;
            std::swap(idx_[vals_[i].second], idx_[vals_[j].second]);
            std::swap(vals_[i], vals_[j]);
        }
        
        void HeapifyUp(int i) {
            while (i != 0)  {            
                int p = (i - 1) / 2;
                if (vals_[i].first <= vals_[p].first) 
                    return;
 
                SwapNode(i, p);                
                i = p;
            }
        }
        
        // Make the heap valid again. O(log(n))
        void HeapifyDown(int i) {
            while (true) {
                int c1 = i*2 + 1;
                int c2 = i*2 + 2;
 
                // No child
                if (c1 >= size_) return;
 
                // Get the index of the max child
                int c = (c2 < size_ 
                      && vals_[c2].first > vals_[c1].first ) ? c2 : c1;
 
                // If key[c] is greater than key[i], swap them and
                // continue to HeapifyDown(c)
                if (vals_[c].first <= vals_[i].first) 
                    return;
                
                SwapNode(c, i);
                i = c;
            }
        }
        
        // {key, id}
        vector<pair<int,int>> vals_;
        
        // Index of the i-th item in vals_ 
        vector<int> idx_;
        
        int size_;
    };
};

// Conclusion:
// Self defind maxHeap. Hard part is here.
//

// version 4:
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        typedef pair<int, int> Event; 
        // events,  x,   h
        vector<Event> es;        
        hs_.clear();
        
        for (const auto& b : buildings) {
            es.emplace_back(b[0], b[2]);
            es.emplace_back(b[1], -b[2]);
        }
        
        // Sort events by x
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2){
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });
        
        vector<pair<int, int>> ans;
        
        // Process all the events
        for (const auto& e: es) {            
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);
            
            if (entering) {                
                if (h > this->maxHeight()) 
                    ans.emplace_back(x, h);
                hs_.insert(h);
            } else {
                hs_.erase(hs_.equal_range(h).first);
                if (h > this->maxHeight())
                    ans.emplace_back(x, this->maxHeight());
            }            
        }
        
        return ans;
    }
private:
    int maxHeight() const {
        if (hs_.empty()) return 0;
        return *hs_.rbegin();
    }
    multiset<int> hs_;
};

//
// Reference: huahua
// Huahua's youtube: https://www.youtube.com/watch?v=8Kd-Tn_Rz7s




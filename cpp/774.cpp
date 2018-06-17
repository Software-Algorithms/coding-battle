/****/
struct interval {
    interval(int d) : num(d), den(1), dist(d) {} // numerator, denominator, distance
    double num, den, dist;
    bool operator< (const interval &d) const {return dist < d.dist;}
    void update() {den++; dist = num/den;}
};

template<typename T>
priority_queue<T> make_priority_queue(vector<int>& v) {
    vector<int> t(v.size());
    adjacent_difference(v.begin(), v.end(), t.begin());
    t.erase(t.begin());
    return priority_queue<T>(t.begin(), t.end());
}

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        auto pq = make_priority_queue<interval>(stations);
        double max_dist = (stations.back() - stations.front()) / static_cast<double>(K+1);
        
        while(K) {
            auto top = pq.top();
            pq.pop();
            while(K && (top.dist >= pq.top().dist || top.dist > max_dist)) {
            top.update();
            K--;
            }
            pq.push(top);
        }
        
        return pq.top().dist;
    }
};

// Reference:
// https://www.youtube.com/watch?v=C_OdHoPJqLQ




/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() < 2) return intervals;
        
        // sort
        sort(intervals.begin(), intervals.end(),
            [](Interval a, Interval b) {
                return a.start < b.start;
            });
        
        vector<Interval> res;
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i].start <= res.back().end) {
                res.back().end = max(intervals[i].end, res.back().end);
            } else {
            	res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};
/**
 * Sort, Map
 *
 * Idea:
 *
 * std::map is default sorted
 * set the key value as the time stamp, and according value as +1 (add 1 meeting room) / -1 (reduce 1 meeting room)
 *
 * For example,
 * Given [[0, 30],[5, 10],[15, 20]],
 * map is constructed as below,
 * [0, 1]
 * [5, 1]
 * [10, -1]
 * [15, 1]
 * [20, -1]
 * [30, -1]
 * Along one traversal, cnt goes like 1, 2, 1, 2, 1, 1. Then maxCnt is 2.
 * return 2.
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> mp; // key: time; val: +1 if start, -1 if end

        for(int i=0; i< intervals.size(); i++) {
            mp[intervals[i].start]++;
            mp[intervals[i].end]--;
        }

        int cnt = 0, maxCnt = 0;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            cnt += it->second;
            maxCnt = max( cnt, maxCnt);
        }

        return maxCnt;
    }
};
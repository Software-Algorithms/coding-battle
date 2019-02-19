/**
 * Code description
 *
 * Author: xpharry
 * Date: 12/3/2018
 *
 * Data structure:
 *    Array
 *
 * Idea:
 *    - Sort.
 *
 * Complexity:
 *    Time: T(n) = n*T(n-1) + O(n^2) ~ O(n!)
 *    Space: O(n)
 *
 * Take-away:
 *    - string initialization: string = str(n, '.') which is similar to vector
 *
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();

        while( it != intervals.end() ) {
        	if(newInterval.end < it->start) {
        		break;
        	} else if(newInterval.start > it->end) {
        		it++;
        	} else {
        		newInterval.start = min(newInterval.start, it->start);
        		newInterval.end = max(newInterval.end, it->end);
        		it = intervals.erase(it);
        	}
        }

        intervals.insert(it, newInterval);

        return intervals;
    }
};

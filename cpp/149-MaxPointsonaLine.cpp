/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size() <= 2) return points.size();
        int res = 0;
        for(int i = 0; i < points.size(); i++) {
            // use hash map, first para is to represent k of the line, the second is the number of the points in the line
            map<pair<int, int>, int> lines;
            // there are three cases for each pair of points:
            // overlap, vertical, others
            int overlap = 0, vertical = 0, localmax = 0;
            for(int j = i+1; j < points.size(); j++) {
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                if(dx == 0 && dy == 0) overlap++;
                else if(dx == 0) vertical++;
                else {
                    int gcd = GCD(dx, dy);
                    dx /= gcd;
                    dy /= gcd;
                    lines[make_pair(dx, dy)]++;
                    localmax = max(localmax, lines[make_pair(dx, dy)]);
                }
                localmax = max(localmax, vertical);
            }
            res = max(res, localmax+overlap+1); // +1 means including itself
        }
        return res;
    }
    
    int GCD(int a, int b) {
        if(b == 0) return a;
        return GCD(b, a%b);
    }
};
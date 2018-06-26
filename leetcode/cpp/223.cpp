/**
 * Math
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = (C-A) * (D-B) + (G-E) * (H-F);

        if (C<=E || A>=G || B>=H || D<=F )
            return total;

        vector <int> h;
        h.push_back(A);
        h.push_back(C);
        h.push_back(E);
        h.push_back(G);

        vector <int> v;
        v.push_back(B);
        v.push_back(D);
        v.push_back(F);
        v.push_back(H);

        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        total = total - (h[2] - h [1]) * (v[2] - v[1]);
        return total;
    }
};


/**
 * Math
 */
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA = (C-A) * (D-B);
        int areaB = (G-E) * (H-F);

        int left = max(A, E);
        int right = min(G, C);
        int bottom = max(F, B);
        int top = min(D, H);

        // If overlap
        int overlap = 0;
        if(right > left && top > bottom)
             overlap = (right - left) * (top - bottom);

        return areaA + areaB - overlap;
    }
};
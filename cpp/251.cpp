/*
 * Design
 */
class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x = vec2d.begin(), e = vec2d.end();
        if (x != e)
            y = x->begin();
    }

    int next() {
        return *y++;
    }

    bool hasNext() {
        while (x != e && y == x->end()) {
            ++x;
            y = x->begin();
        }
        return x != e;
    }

private:
    vector<vector<int>>::iterator x, e;
    vector<int>::iterator y;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

/* ------------------------------
 * Post-Completion Note:
 * std::vector::end
 * Return iterator to end
 * Returns an iterator referring to the past-the-end element in the vector container.
 *
 * The past-the-end element is the theoretical element that would follow the last element in the vector.
 * It does not point to any element, and thus shall not be referenced.
 * ------------------------------
 */

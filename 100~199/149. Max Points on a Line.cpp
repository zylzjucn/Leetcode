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
    int maxPoints(vector<Point>& p) {
        int res = 0;
        for (int i = 0; i < p.size(); i++) {
            map<pair<int, int>, int> m;
            int overlap = 1;
            // int vertical = 0;
            for (int j = i + 1; j < p.size(); j++) {
                if (p[i].x == p[j].x && p[i].y == p[j].y)
                    overlap++;
                // else if (p[i].x == p[j].x)
                //     vertical++;
                else {
                    int x = p[j].x - p[i].x;
                    int y = p[j].y - p[i].y;
                    int g = gcd(x, y);
                    pair<int, int> xy;
                    xy = make_pair(x / g, y / g);
                    m[xy]++;
                }
            }
            for (auto pxy : m)
                res = max(res, overlap + pxy.second);
            res = max(res, overlap);
        }
        return res;
    }
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};

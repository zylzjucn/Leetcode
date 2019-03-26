class Solution {
public:
    int shortestDistance(vector<string>& v, string w1, string w2) {
        int res = v.size();
        int p1 = -1;
        int p2 = -1;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == w1) {
                p1 = i;
                if (p2 != -1)
                    res = min(res, p1 - p2);
            }
            else if (v[i] == w2) {
                p2 = i;
                if (p1 != -1)
                    res = min(res, p2 - p1);
            }
        }
        return res;
    }
};

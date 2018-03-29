class Solution {
public:
    int rob(vector<int>& n) {
        int a = 0, b = 0, i = 0, r;
        for (; i < n.size(); i++) {
            if (i % 2 == 0)
                a = max(a + n[i], b);
            else
                b = max(b + n[i], a);
        }
        r = max(a, b);
        return r;
    }
};

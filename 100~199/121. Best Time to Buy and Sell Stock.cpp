class Solution {
public:
    int maxProfit(vector<int>& v) {
        if (!v.size())
            return 0;
        int a = v[0], b = 0;
        for (int i = 0; i < v.size() - 1; i++) {
            a = min(a, min(v[0], v[i]));
            b = max(v[i + 1] - a, b);
        }
        return b;
    }
};

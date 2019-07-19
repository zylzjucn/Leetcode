class Solution {
public:
    int totalHammingDistance(vector<int>& n) {
        int maxn = 0;
        for (const auto& x : n)
            maxn = max(maxn, x);
        vector<int> v0;
        while (maxn) {
            v0.push_back(0);
            maxn /= 2;
        }
        vector<int> v1(v0);
        for (auto x : n) {
            int i = 0;
            for (; x; i++) {
                if (x % 2 == 0)
                    v0[i]++;
                else
                    v1[i]++;
                x /= 2;
            }
            while (i < v0.size())
            v0[i++]++;
        }
        int res = 0;
        for (int i = 0; i < v0.size(); i++)
            res += v0[i] * v1[i];
        return res;
    }
};

class Solution {
public:
    int coinChange(vector<int>& v, int t) {
        vector<int> res(t + 1, t + 1);
        res[0] = 0;
        for (int i = 1; i <= t; i++) {
            for (const auto& p : v)
                if (i - p >= 0)
                    res[i] = min(res[i], res[i - p] + 1);
        }
        return res.back() == t + 1 ? -1 : res.back();
    }
};

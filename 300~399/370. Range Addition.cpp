class Solution {
public:
    vector<int> getModifiedArray(int len, vector<vector<int>>& updates) {
        vector<int> res(len, 0);
        for (const auto& v : updates) {
            res[v[0]] += v[2];
            if (v[1] + 1 < len)
                res[v[1] + 1] -= v[2];
        }
        int x = 0;
        for (int i = 0; i < res.size(); i++) {
            res[i] += x;
            x = res[i];
        }
        return res;
    }
};

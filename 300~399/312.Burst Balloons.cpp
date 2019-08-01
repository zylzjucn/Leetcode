class Solution {
public:
    int maxCoins(vector<int>& n) {
        vector<int> v = {1};
        for (const auto& i : n)
            v.push_back(i);
        v.push_back(1);
        int len = v.size();
        vector<vector<int>> res(len, vector<int>(len, 0));
        for (int left = len - 2; left >= 0; left--)
            for (int right = left + 2; right < len; right++)
                for (int i = left + 1; i < right; i++)
                    res[left][right] = max(res[left][right], res[left][i] + v[left] * v[i] * v[right] + res[i][right]);
        return res[0].back();
    }
};

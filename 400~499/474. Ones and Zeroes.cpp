class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> res(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 0; i < strs.size(); i++) {
            int zeros = 0;
            int ones = 0;
            for (const auto& c : strs[i]) {
                if (c == '0')
                    zeros++;
                else
                    ones++;
            }
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j >= zeros && k >= ones) {
                        res[i + 1][j][k] = max(res[i][j - zeros][k - ones] + 1, res[i][j][k]);
                    }
                    else
                        res[i + 1][j][k] = res[i][j][k];
                }
            }
        }
        return res.back().back().back();
    }
};

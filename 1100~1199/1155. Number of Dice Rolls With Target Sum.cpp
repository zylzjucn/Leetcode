class Solution {
public:
    int numRollsToTarget(int d, int f, int t) {
        vector<vector<int>> m(d + 1, vector<int>(t + 1, 0));
        m[0][0] = 1;
        for (int i = 0; i < d; i++)
            for (int j = i; j <= f * i && j <= t; j++)
                for (int k = 1; k <= f && j + k <= t; k++) {
                    m[i + 1][j + k] += m[i][j];
                    if (m[i + 1][j + k] >= 1000000007)
                        m[i + 1][j + k] -= 1000000007;
                }
        return m.back().back() % 1000000007;
    }
};

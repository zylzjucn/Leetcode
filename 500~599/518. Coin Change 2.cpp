class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> m(coins.size() + 1, vector<int>(amount + 1, 0));
        for (int i = 0; i < m.size(); i++)
            m[i][0] = 1;
        for (int i = 1; i < m.size(); i++)
            for (int j = 1; j < m[0].size(); j++) {
                m[i][j] += m[i - 1][j];
                if (j >= coins[i - 1])
                    m[i][j] += m[i][j - coins[i - 1]];
            }
        return m.back().back();
    }
};

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int row = d.size();
        int col = d[0].size();
        vector<vector<int>> m(row, vector<int>(col, 0));
        m.back().back() = - d.back().back();
        for (int j = col - 2; j >= 0; j--)
            m[row - 1][j] = max(m[row - 1][j + 1], 0) - d[row - 1][j];
        for (int i = row - 2; i >= 0; i--)
            m[i][col - 1] = max(m[i + 1][col - 1], 0) - d[i][col - 1];
        for (int i = row - 2; i >= 0; i--)
            for (int j = col - 2; j >= 0; j--)
                m[i][j] = max(min(m[i + 1][j], m[i][j + 1]), 0) - d[i][j];
        return max(m[0][0] + 1, 1);
    }
};

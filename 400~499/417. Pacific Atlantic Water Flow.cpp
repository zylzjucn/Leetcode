class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& m) {
        vector<vector<int>> res;
        int row = m.size();
        if (row == 0)
            return res;
        int col = m[0].size();
        if (col == 0)
            return res;
        vector<vector<int>> p(row, vector<int>(col, 0));
        vector<vector<int>> a(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            p[i][0] = 1;
            a[i][col - 1] = 1;
        }
        for (int j = 0; j < col; j++) {
            p[0][j] = 1;
            a[row - 1][j] = 1;
        }
        for (int i = 0; i < row; i++) {
            paint(m, p, i, 0);
            paint(m, a, i, col - 1);
        }
        for (int j = 0; j < col; j++) {
            paint(m, p, 0, j);
            paint(m, a, row - 1, j);
        }
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (p[i][j] && a[i][j]) {
                    vector<int> r = {i, j};
                    res.push_back(r);
                }
        return res;
    }
    void paint(vector<vector<int>>& m, vector<vector<int>>& v, int i, int j) {
        if (v[i][j] && (i > 0 && i < v.size() - 1) && (j > 0 && j < v[0].size() - 1))
            return;
        v[i][j] = 1;
        if (i > 0 && m[i - 1][j] >= m[i][j] && v[i - 1][j] == 0)
            paint(m, v, i - 1, j);
        if (i < v.size() - 1 && m[i + 1][j] >= m[i][j] && v[i + 1][j] == 0)
            paint(m, v, i + 1, j);
        if (j > 0 && m[i][j - 1] >= m[i][j] && v[i][j - 1] == 0)
            paint(m, v, i, j - 1);
        if (j < v[0].size() - 1 && m[i][j + 1] >= m[i][j] && v[i][j + 1] == 0)
            paint(m, v, i, j + 1);
    }
};

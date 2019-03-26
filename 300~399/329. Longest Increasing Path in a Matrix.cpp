class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& m) {
        int row = m.size();
        if (row == 0)
            return 0;
        int col = m[0].size();
        if (col == 0)
            return 0;
        int len = 0;
        vector<vector<int>> v(row, vector<int>(col, 0));
        int count = 0;
        while (count < row * col) {
            vector<vector<int>> tmp = v;
            len++;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (v[i][j] == 0 && ismin(m, v, i, j, row, col)) {
                        tmp[i][j] = len;
                        count++;
                    }
                }
            }
            v = tmp;
        }
        return len;
    }
    bool ismin(vector<vector<int>>& m, vector<vector<int>>& v, int i, int j, int row, int col) {
        if (i > 0 && v[i - 1][j] == 0 && m[i - 1][j] < m[i][j])
            return false;
        if (i < row - 1 && v[i + 1][j] == 0 && m[i + 1][j] < m[i][j])
            return false;
        if (j > 0 && v[i][j - 1] == 0 && m[i][j - 1] < m[i][j])
            return false;
        if (j < col - 1 && v[i][j + 1] == 0 && m[i][j + 1] < m[i][j])
            return false;
        return true;
    }
};

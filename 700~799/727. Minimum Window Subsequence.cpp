class Solution {
public:
    string minWindow(string s, string t) {
        int row = t.length() + 1;
        int col = s.length() + 1;
        int len = col + 1;
        int pos = -1;
        vector<vector<int>> v(row, vector<int>(col, -1));
        for (int j = 0; j < col; j++)
            v[0][j] = 0;
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (t[i - 1] == s[j - 1]) {
                    if (v[i - 1][j - 1] != -1)
                        v[i][j] = v[i - 1][j - 1] + 1;
                }
                else if (v[i][j - 1] != -1)
                    v[i][j] = v[i][j - 1] + 1;
            }
        }
        for (int j = 0; j < col; j++)
            if (v[row - 1][j] != -1 && v[row - 1][j] < len) {
                len = v[row - 1][j];
                pos = j - len;
            }
        return pos == -1 ? "" : s.substr(pos, len);
    }
};

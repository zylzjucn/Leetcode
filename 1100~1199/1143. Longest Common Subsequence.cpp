class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int row = s.length() + 1;
        int col = t.length() + 1;
        vector<vector<int>> m(row, vector<int>(col, 0));
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++) {
                if (s[i - 1] == t[j - 1])
                    m[i][j] = m[i - 1][j - 1] + 1;
                else
                    m[i][j] = max(max(m[i - 1][j - 1], m[i - 1][j]), m[i][j - 1]);
            }
        return m.back().back();
    }
};

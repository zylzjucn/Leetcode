class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> v(s.length() + 1, vector<bool>(p.length() + 1, 0));
        v[0][0] = 1;
        for (int j = 2; j <= p.length(); j++)
            if (p[j - 1] == '*')
                v[0][j] = v[0][j - 2];
        for (int i = 1; i <= s.length(); i++)
            for (int j = 1; j <= p.length(); j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    v[i][j] = v[i - 1][j - 1];
                if (p[j - 1] == '*' && j > 1) {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                        v[i][j] = v[i - 1][j - 1] || v[i - 1][j];
                    if (v[i][j - 2] || v[i][j - 1])
                        v[i][j] = 1;
                }
            }
        return v.back().back();
    }
};

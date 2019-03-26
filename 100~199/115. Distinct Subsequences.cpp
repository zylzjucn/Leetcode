class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> m(s.length() + 1, vector<int> (t.length() + 1));
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if (i == 0)
                    m[i][j] = 0;
                if (j == 0)
                    m[i][j] = 1;
                if (i > 0 && j > 0) {
                    m[i][j] = m[i - 1][j];
                    if (s[i - 1] == t[j - 1])
                        m[i][j] += m[i - 1][j - 1];
                }   
            }
        }
        return m.back().back();
    }
};

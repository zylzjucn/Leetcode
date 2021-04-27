class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> m(s.length() + 1, vector<int>(s.length() + 1, 0));
        for (int i = 0; i < m.size() - 1; i++)
            m[i][i + 1] = 1;
        for (int i = 2; i <= s.length(); i++) {
            for (int j = 0; i + j <= s.length(); j++) {
                m[j][i + j] = max(m[j + 1][i + j], m[j][i + j - 1]);
                if (s[i + j - 1] == s[j])
                    m[j][i + j] = max(m[j][i + j], m[j + 1][i + j - 1] + 2);
            }
        }
        return m[0].back();
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> m(s1.length() + 1, vector<int>(s2.length() + 1, 0));
        for (int i = 0; i < s1.length(); i++)
            m[i + 1][0] = m[i][0] + s1[i];
        for (int j = 0; j < s2.length(); j++)
            m[0][j + 1] = m[0][j] + s2[j];
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 0; j < s2.length(); j++) {
                if (s1[i] == s2[j])
                    m[i + 1][j + 1] = m[i][j];
                else
                    m[i + 1][j + 1] = min(m[i][j + 1] + s1[i], m[i + 1][j] + s2[j]);
            }
        }
        return m.back().back();
    }
};

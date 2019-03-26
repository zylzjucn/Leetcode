class Solution {
public:
    int minDistance(string s, string t) {
        vector<vector<int>> v(s.length() + 1, vector<int> (t.length() + 1));
        for (int i = 0; i <= s.length(); i++)
            for (int j = 0; j <= t.length(); j++) {
                if (i == 0)
                    v[i][j] = j;
                else if (j == 0)
                    v[i][j] = i;
                else {
                    if (s[i - 1] == t[j - 1])
                        v[i][j] = v[i - 1][j - 1];
                    else
                        v[i][j] = min(v[i - 1][j - 1], min(v[i - 1][j], v[i][j - 1])) + 1;
                }
        }
        return v.back().back();
    }
};

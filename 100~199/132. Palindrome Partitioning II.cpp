class Solution {
public:
    int minCut(string s) {
        vector<int> v(s.length() + 1, 0);
        for (int i = 0; i <= s.length(); i++)
            v[i] = i - 1;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; i - j >= 0 && i + j < s.length() && s[i - j] == s[i + j]; j++)
                v[i + j + 1] = min(v[i - j] + 1, v[i + j + 1]);
            for (int j = 1; i - j + 1>= 0 && i + j < s.length() && s[i - j + 1] == s[i + j]; j++)
                v[i + j + 1] = min(v[i - j + 1] + 1, v[i + j + 1]);
        }
        return v.back();
    }
};

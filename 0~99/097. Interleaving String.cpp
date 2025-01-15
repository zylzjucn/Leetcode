class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }
        vector<vector<bool>> v(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        v[0][0] = true;
        for (int i = 1; i < v.size(); i++) {
            if (v[i-1][0] && s1[i-1] == s3[i-1]) {
                v[i][0] = true;
            }
        }
        for (int j = 1; j < v[0].size(); j++) {
            if (v[0][j-1] && s2[j-1] == s3[j-1]) {
                v[0][j] = true;
            }
        }
        for (int i = 1; i < v.size(); i++) {
            for (int j = 1; j < v[0].size(); j++) {
                if ((v[i-1][j] && s1[i-1] == s3[i+j-1]) || (v[i][j-1] && s2[j-1] == s3[i+j-1])) {
                    v[i][j] = true;
                }
            }
        }
        return v.back().back();
    }
};

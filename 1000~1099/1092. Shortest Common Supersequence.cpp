class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int i = 0;
        int j = 0;
        string res = "";
        for (const auto& c : LCS(str1, str2)) {
            while (str1[i] != c)
                res += str1[i++];
            while (str2[j] != c)
                res += str2[j++];
            res += c;
            i++;
            j++;
        }
        return res + str1.substr(i) + str2.substr(j);
    }
    
    string LCS(const string& s1, const string& s2) {
        vector<vector<string>> m(s1.length() + 1, vector<string>(s2.length() + 1, ""));
        for (int i = 0; i < s1.length(); i++)
            for (int j = 0; j < s2.length(); j++) {
                if (s1[i] == s2[j])
                    m[i + 1][j + 1] = m[i][j] + s1[i];
                else
                    m[i + 1][j + 1] = m[i + 1][j].length() > m[i][j + 1].length() ? m[i + 1][j] : m[i][j + 1];
            }
        return m.back().back();
    }
    
};

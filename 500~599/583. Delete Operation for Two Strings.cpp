class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size() + 1;
        int len2 = word2.size() + 1;
        vector<vector<int>> v(len1, vector<int>(len2, 0));
        for (int i = 0; i < len1; i++)
            for (int j = 0; j < len2; j++) {
                if (i == 0)
                    v[i][j] = j;
                else if (j == 0)
                    v[i][j] = i;
                else {
                    if (word1[i - 1] == word2[j - 1])
                        v[i][j] = v[i - 1][j - 1];
                    else
                        v[i][j] = min(v[i - 1][j], v[i][j - 1]) + 1;
                }
            }
        return v.back().back();
    }
};

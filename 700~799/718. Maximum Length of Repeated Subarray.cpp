class Solution {
public:
    int findLength(vector<int>& v1, vector<int>& v2) {
        int res = 0;
        vector<vector<int>> m(v1.size() + 1, vector<int>(v2.size() + 1, 0));
        for (int i = 0; i < v1.size(); i++)
            for (int j = 0; j < v2.size(); j++) {
                if (v1[i] == v2[j])
                    m[i + 1][j + 1] = m[i][j] + 1;
                else
                    m[i + 1][j + 1] = 0;
                res = max(res, m[i + 1][j + 1]);
            }
        return res;
    }
};

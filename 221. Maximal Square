class Solution {
public:
    int maximalSquare(vector<vector<char>>& v) {
        if (v.empty())
            return 0;
        int m = v.size(), n = v[0].size(), i, j, l = 0;
        vector<vector<int>> v1(m, vector<int>(n, 0));
        for (i = 0; i < m; i++) {
            v1[i][0] = v[i][0] - '0';
            l = max(l, v1[i][0]);
        }
        for (j = 1; j < n; j++) {
            v1[0][j] = v[0][j] - '0';
            l = max(l, v1[0][j]);
        }
        for (i = 1; i < m; i++)
            for (j = 1; j < n; j++)
            {
                if(v[i][j] == '1')
                    v1[i][j] = min(v1[i - 1][j - 1], min(v1[i][j - 1], v1[i - 1][j])) + 1;
                l = max(l, v1[i][j]);
            }
        return l * l;
    }
};

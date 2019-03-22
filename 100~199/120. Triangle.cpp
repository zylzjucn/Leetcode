class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int i, j;
        vector<int> v(t.back());
        for (i = t.size() - 2; i >= 0 ; i--)
            for (j = 0; j <= i; j++)
                v[j] = min(v[j], v[j + 1]) + t[i][j];
        return v[0];
    }
};

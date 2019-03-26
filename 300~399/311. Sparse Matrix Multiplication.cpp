class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        // mp * pn -> mn 12 21 11
        int m = A.size();
        int p = A[0].size();
        int n = B[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < p; k++)
                    res[i][j] += A[i][k] * B[k][j];
        return res;
    }
};

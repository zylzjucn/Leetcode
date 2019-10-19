class Solution {
public:
    int findPaths(int m, int n, int N, int row, int col) {
        vector<vector<int>> pre(m, vector<int>(n, 0));
        int res = 0;
        if (N == 0)
            return res;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i == 0)
                    pre[i][j]++;
                if (j == 0)
                    pre[i][j]++;
                if (i == m - 1)
                    pre[i][j]++;
                if (j == n - 1)
                    pre[i][j]++;
            }
        res += pre[row][col];
        for (int move = 1; move < N; move++) {
            vector<vector<int>> cur(m, vector<int>(n, 0));
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != 0)
                        cur[i][j] += pre[i - 1][j];
                    cur[i][j] %= 1000000007;
                    if (i != m - 1)
                        cur[i][j] += pre[i + 1][j];
                    cur[i][j] %= 1000000007;
                    if (j != 0)
                        cur[i][j] += pre[i][j - 1];
                    cur[i][j] %= 1000000007;
                    if (j != n - 1)
                        cur[i][j] += pre[i][j + 1];
                    cur[i][j] %= 1000000007;
                }
            }
            res += cur[row][col];
            res %= 1000000007;
            pre = cur;
        }
        return res;
    }
};

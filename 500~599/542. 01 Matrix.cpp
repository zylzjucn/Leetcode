class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& m) {
        int row = m.size();
        if (row == 0)
            return m;
        int col = m[0].size();
        int d = 1;
        queue<int> q;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (m[i][j] != 0)
                    m[i][j] = INT_MAX;
                else {
                    q.push(i);
                    q.push(j);
                }
            }
        q.push(-1);
        while (q.size() > 1) {
            int i = q.front();
            q.pop();
            if (i == -1) {
                d++;
                q.push(-1);
                continue;
            }
            int j = q.front();
            q.pop();
            if (i > 0 && m[i - 1][j] > d) {
                m[i - 1][j] = d;
                q.push(i - 1);
                q.push(j);
            }
            if (i < row - 1 && m[i + 1][j] > d) {
                m[i + 1][j] = d;
                q.push(i + 1);
                q.push(j);
            }
            if (j > 0 && m[i][j - 1] > d) {
                m[i][j - 1] = d;
                q.push(i);
                q.push(j - 1);
            }
            if (j < col - 1 && m[i][j + 1] > d) {
                m[i][j + 1] = d;
                q.push(i);
                q.push(j + 1);
            }
        }
        return m;
    }
};

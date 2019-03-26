class Solution {
public:
    void wallsAndGates(vector<vector<int>>& m) {
        queue<vector<int>> q;
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                if (m[i][j] == 0) {
                    vector<int> v = {i ,j};
                    q.push(v);
                }
        while (!q.empty())
            update(m, q);
    }
    void update(vector<vector<int>>& m, queue<vector<int>>& q) {  // BFS is better here cuz +1 every level, only update once
        int INF = 2147483647;
        int i = q.front()[0];
        int j = q.front()[1];
        q.pop();
        if (i > 0 && m[i - 1][j] == INF) {
            m[i - 1][j] = m[i][j] + 1;
            q.push(vector<int>{i - 1, j});
        }
        if (i < m.size() - 1 && m[i + 1][j] == INF) {
            m[i + 1][j] = m[i][j] + 1;
            q.push(vector<int>{i + 1, j});
        }
        if (j > 0 && m[i][j - 1] == INF) {
            m[i][j - 1] = m[i][j] + 1;
            q.push(vector<int>{i, j - 1});
        }
        if (j < m[0].size() - 1 && m[i][j + 1] == INF) {
            m[i][j + 1] = m[i][j] + 1;
            q.push(vector<int>{i, j + 1});
        }
    }
};

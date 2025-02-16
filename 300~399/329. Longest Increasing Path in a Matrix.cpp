class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& m) {
        int row = m.size();
        if (row == 0)
            return 0;
        int col = m[0].size();
        if (col == 0)
            return 0;
        int len = 0;
        vector<vector<int>> v(row, vector<int>(col, 0));
        int count = 0;
        while (count < row * col) {
            vector<vector<int>> tmp = v;
            len++;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    if (v[i][j] == 0 && ismin(m, v, i, j, row, col)) {
                        tmp[i][j] = len;
                        count++;
                    }
                }
            }
            v = tmp;
        }
        return len;
    }
    bool ismin(vector<vector<int>>& m, vector<vector<int>>& v, int i, int j, int row, int col) {
        if (i > 0 && v[i - 1][j] == 0 && m[i - 1][j] < m[i][j])
            return false;
        if (i < row - 1 && v[i + 1][j] == 0 && m[i + 1][j] < m[i][j])
            return false;
        if (j > 0 && v[i][j - 1] == 0 && m[i][j - 1] < m[i][j])
            return false;
        if (j < col - 1 && v[i][j + 1] == 0 && m[i][j + 1] < m[i][j])
            return false;
        return true;
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        auto comp = [&matrix](const pair<int, int>& a, const pair<int, int>& b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                pq.push(make_pair(i, j));
            }
        }
        vector m(matrix.size(), vector(matrix[0].size(), 1));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0;
        while (!pq.empty()) {
            int i = pq.top().first;
            int j = pq.top().second;
            pq.pop();
            for (const auto& direction : directions) {
                int new_i = i + direction.first;
                int new_j = j + direction.second;
                if (new_i >= 0 && new_i < matrix.size() && new_j >= 0 && new_j < matrix[0].size()) {
                    if (matrix[i][j] < matrix[new_i][new_j]) {
                        m[new_i][new_j] = max(m[new_i][new_j], m[i][j] + 1);
                    }
                }
            }
        }
        for (int i = 0; i < matrix.size(); i ++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                res = max(res, m[i][j]);
            }
        }
        return res;
    }
};

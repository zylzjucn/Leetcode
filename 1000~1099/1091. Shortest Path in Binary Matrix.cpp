class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) {
            return -1;
        }
        vector<vector<int>> m(grid.size(), vector<int>(grid[0].size(), -1));
        m[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({-1, -1});
        int len = 2;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        while (q.size() > 1) {
            auto [i, j] = q.front();
            q.pop();
            if (i == -1) {
                q.push({-1, -1});
                len++;
                continue;
            }
            for (const auto& direction : directions) {
                int new_i = i + direction.first;
                int new_j = j + direction.second;
                if (new_i >= 0 && new_i < m.size() && new_j >= 0 && new_j < m[0].size() && grid[new_i][new_j] == 0 && m[new_i][new_j] == -1) {
                    m[new_i][new_j] = len;
                    q.push({new_i, new_j});
                }
            }
            if (i == m.size() - 1 && j == m[0].size() - 1) {
                break;
            }
        }
        return m.back().back();
    }
};

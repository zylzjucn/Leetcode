class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), INT_MAX));
        queue<pair<int, int>> q;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    res[i][j] = 0;
                }
            }
        }
        q.push({-1, -1});
        int distance = 1;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (q.size() > 1) {
            auto [i, j] = q.front();
            q.pop();
            if (i == -1) {
                distance++;
                q.push({-1, -1});
            } else {
                for (const auto& direction : directions) {
                    int new_i = i + direction.first;
                    int new_j = j + direction.second;
                    if (new_i >= 0 && new_i < res.size() && new_j >= 0 && new_j < res[0].size() && res[new_i][new_j] == INT_MAX) {
                        res[new_i][new_j] = distance;
                        q.push({new_i, new_j});
                    }
                }
            }
        }
        return res;
    }
};

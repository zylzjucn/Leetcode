class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX;
        vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int id_building = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    id_building--;
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));
                    int distance = 0;
                    q.push(make_pair(-1, -1));
                    while (q.size() > 1) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        if (row == -1) {
                            distance++;
                            q.push(make_pair(-1, -1));
                            continue;
                        }
                        distances[row][col] += distance;
                        for (const auto& direction : directions) {
                            int row_new = row + direction[0];
                            int col_new = col + direction[1];
                            if (row_new >= 0 && row_new < grid.size() && col_new >= 0 && col_new < grid[0].size() && grid[row_new][col_new] == id_building + 1) {
                                q.push(make_pair(row_new, col_new));
                                grid[row_new][col_new] = id_building;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == id_building)
                    res = min(res, distances[i][j]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

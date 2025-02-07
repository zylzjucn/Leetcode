class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX;
        vector reach(grid.size(), vector<int>(grid[0].size(), 0));
        vector distances(grid.size(), vector<int>(grid[0].size(), 0));
        int building = 0;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    building++;
                    vector visited(grid.size(), vector<bool>(grid[0].size(), false));
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    int distance = 0;
                    while (!q.empty()) {
                        int len = q.size();
                        for (int k = 0; k < len; k++) {
                            auto [x, y] = q.front();
                            q.pop();
                            distances[x][y] += distance;
                            reach[x][y]++;
                            for (const auto& direction : directions) {
                                int new_x = x + direction.first;
                                int new_y = y + direction.second;
                                if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size() || visited[new_x][new_y] || grid[new_x][new_y] > 0) {
                                    continue;
                                }
                                q.push({new_x, new_y});
                                visited[new_x][new_y] = true;
                            }
                        }
                        distance++;
                    }
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0 && building == reach[i][j]) {
                    res = min(res, distances[i][j]);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};

class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = INT_MAX;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<tuple<int, int, int>> pq;
        pq.emplace(grid[0][0], 0, 0);
        grid[0][0] = -1;
        while (!pq.empty()) {
            auto [val, i, j] = pq.top();
            pq.pop();
            res = min(res, val);
            if (i == row - 1 && j == col - 1)
                break;
            for (const auto& dir : dirs) {
                int i_new = i + dir[0];
                int j_new = j + dir[1];
                if (i_new >= 0 && i_new < row && j_new >= 0 && j_new < col && grid[i_new][j_new] >= 0) {
                    pq.emplace(grid[i_new][j_new], i_new, j_new);
                    grid[i_new][j_new] = -1;
                }
            }
        }
        return res;
    }
};

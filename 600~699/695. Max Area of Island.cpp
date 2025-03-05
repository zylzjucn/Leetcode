class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int cur = 0;
                    calculateIsland(grid, i, j, cur);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }

    void calculateIsland(vector<vector<int>>& grid, int i, int j, int& cur) {
        if (i < 0 | i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        cur++;
        grid[i][j] = 0;
        calculateIsland(grid, i - 1, j, cur);
        calculateIsland(grid, i + 1, j, cur);
        calculateIsland(grid, i, j - 1, cur);
        calculateIsland(grid, i, j + 1, cur);
    }
};

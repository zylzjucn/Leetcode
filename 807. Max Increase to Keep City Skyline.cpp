class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> vx;
        vector<int> vy;
        int sum = 0;
        for (int i = 0; i < grid.size(); i++) {
            int top = 0;
            for (int j = 0; j < grid[0].size(); j++)
                top = max(top, grid[i][j]);
            vx.push_back(top);
        }
        for (int j = 0; j < grid[0].size(); j++) {
            int top = 0;
            for (int i = 0; i < grid.size(); i++)
                top = max(top, grid[i][j]);
            vy.push_back(top);
        }
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                sum += min(vx[i], vy[j]) - grid[i][j];
        return sum;
    }
};

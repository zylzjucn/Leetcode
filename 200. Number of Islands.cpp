class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size(), i = 0, j = 0, count = 0;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (grid[i][j]=='1') {
                    dfs(grid, i, j);
                    count++;
                }
        return count;
    }
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 || grid[i][j]!='1')
            return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

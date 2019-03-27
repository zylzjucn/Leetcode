class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        if (grid.size() < 3 || grid[0].size() < 3)
            return 0;
        int result = 0;
        for (int i = 0; i < grid.size() - 2; ++i)
            for (int j = 0; j < grid[0].size() - 2; ++j)
                if (isMagicSquare(grid, i, j))
                    result++;
        return result;
    }
    bool isMagicSquare(vector<vector<int>>& grid, int i, int j) {
        if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15)
            return false;
        if (grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2] != 15)
            return false;
        if (grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2] != 15)
            return false;
        if (grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15)
            return false;
        if (grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1] != 15)
            return false;
        if (grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2] != 15)
            return false;
        if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15)
            return false;
        if (grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] != 15)
            return false;
        for (int row = 0; row < 3; ++row)
            for (int column = 0; column < 3; ++column)
                if (grid[i + row][j + column] <= 0 || grid[i + row][j + column] > 9)
                    return false;
        return true;
    }
};

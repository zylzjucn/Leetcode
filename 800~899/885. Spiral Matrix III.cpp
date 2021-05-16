class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int count = 1;
        int i = rStart;
        int j = cStart;
        int k = 0;
        res.push_back({i, j});
        int len = 2;
        while (count < rows * cols) {
            for (int l = 0; l < len / 2; l++) {
                i += dirs[k][0];
                j += dirs[k][1];
                if (i >= 0 && i < rows && j >= 0 && j < cols) {
                    res.push_back({i, j});
                    count++;
                }
            }
            len++;
            k = (k + 1) % 4;
        }
        return res;
    }
};

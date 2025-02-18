class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> res;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<pair<int, int>> fix_directions = {{1, -1}, {-1, -1}, {-1, 1}, {1, 1}};
        int dir = 0;
        int i = 0;
        int j = 0;
        while (res.size() < matrix.size() * matrix[0].size()) {
            if (i < up || i > bottom || j < left || j > right) {
                i += fix_directions[dir].first;
                j += fix_directions[dir].second;
                if (dir == 0) {
                    up++;
                } else if (dir == 1) {
                    right--;
                } else if (dir == 2) {
                    bottom--;
                } else {
                    left++;
                }
                dir = (dir + 1) % 4;
            }
            res.push_back(matrix[i][j]);
            i += directions[dir].first;
            j += directions[dir].second;
        }
        return res;
    }
};

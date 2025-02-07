class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> horizontal(grid[0].size(), 0);
        vector<int> vertical(grid.size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                vertical[i] += grid[i][j];
                horizontal[j] += grid[i][j];
            }
        }
        int res = 0;
        int left = 0, right = horizontal.size() - 1;
        int left_count = horizontal[0], right_count = horizontal.back();
        while (left < right) {
            if (left_count < right_count) {
                left++;
                res += left_count;
                left_count += horizontal[left];
            } else {
                right--;
                res += right_count;
                right_count += horizontal[right];
            }
        }
        int up = 0, bottom = vertical.size() - 1;
        int up_count = vertical[0], bottom_count = vertical.back();
        while (up < bottom) {
            if (up_count < bottom_count) {
                up++;
                res += up_count;
                up_count += vertical[up];
            } else {
                bottom--;
                res += bottom_count;
                bottom_count += vertical[bottom];
            }
        }
        return res;
    }
};

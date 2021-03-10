class Solution {
public:
    int largestIsland(vector<vector<int>>& m) {
        int res  = 0;
        vector<vector<int>> location(m.size(), vector<int>(m[0].size(), -1));
        unordered_map<int, int> area;
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if (m[i][j] == 1) {
                    int index = i * m[0].size() + j;
                    area[index] = 0;
                    find(m, i, j, index, area, location);
                }
            }
        }
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if (m[i][j] == 0) {
                    int cur_area = 1;
                    unordered_set<int> s;
                    if (i > 0 && m[i - 1][j] == -1)
                        s.insert(location[i - 1][j]);
                    if (i < m.size() - 1 && m[i + 1][j] == -1)
                        s.insert(location[i + 1][j]);
                    if (j > 0 && m[i][j - 1] == -1)
                        s.insert(location[i][j - 1]);
                    if (j < m[0].size() - 1 && m[i][j + 1] == -1)
                        s.insert(location[i][j + 1]);
                    for (const auto& k : s) {
                        cur_area += area[k];
                    }
                    res = max(res, cur_area);
                }
            }
        }
        return res == 0 ? m.size() * m[0].size() : res;
    }
    
    void find(vector<vector<int>>& m, int row, int col, int index, unordered_map<int, int>& area, vector<vector<int>>& location) {
        m[row][col] = -1;
        location[row][col] = index;
        area[index]++;
        if (row > 0 && m[row - 1][col] == 1)
            find(m, row - 1, col, index, area, location);
        if (row < m.size() - 1 && m[row + 1][col] == 1)
            find(m, row + 1, col, index, area, location);
        if (col > 0 && m[row][col - 1] == 1)
            find(m, row, col - 1, index, area, location);
        if (col < m[0].size() - 1 && m[row][col + 1] == 1)
            find(m, row, col + 1, index, area, location);
    }
};

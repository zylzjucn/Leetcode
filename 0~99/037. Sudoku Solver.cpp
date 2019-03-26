class Solution {
public:
    void solveSudoku(vector<vector<char>>& m) {
        bool found = false;
        find(m, 0, 0, found);
    }
    void find(vector<vector<char>>& m, int row, int col, bool &found) { // should set a bool found here
        if (m[row][col] == '.') {
            for (char c = '1'; c <= '9'; c++) {
                if (isvalid(m, row, col, c)) {
                    m[row][col] = c;
                    if (col != 8)
                        find(m, row, col + 1, found);
                    else if (row != 8)
                        find(m, row + 1, 0, found);
                    else
                        found = true;
                    if (found)
                        return;
                    m[row][col] = '.';
                }
            }
        }
        else {
            if (col != 8)
                find(m, row, col + 1, found);
            else if (row != 8)
                find(m, row + 1, 0, found);
            else
                found = true;
        }
    }
    bool isvalid(vector<vector<char>>& m, int row, int col, char c) {
        for (int i = 0; i < 9; i++)
            if (m[row][i] == c || m[i][col] == c)
                return false;
        int brow = row / 3 * 3;
        int bcol = col / 3 * 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (m[brow + i][bcol + j] == c)
                    return false;
        return true;
    }
};

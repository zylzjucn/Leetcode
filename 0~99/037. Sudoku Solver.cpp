class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool found = false;
        solveSudoku(board, 0, 0, found);
    }

    void solveSudoku(vector<vector<char>>& board, int row, int col, bool& found) {
        if (found) {
            return;
        }
        if (col == 9) {
            col = 0;
            row++;
        }
        if (row == 9) {
            found = true;
            return;
        }
        if (board[row][col] == '.') {
            for (char c = '1'; c <= '9'; c++) {
                if (isValid(board, row, col, c)) {
                    board[row][col] = c;
                    solveSudoku(board, row, col + 1, found);
                    if (found) {
                        return;
                    }
                    board[row][col] = '.';
                }
            }
        } else {
            solveSudoku(board, row, col + 1, found);
        }
    }

    bool isValid(const vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == c) {
                return false;
            }
        }
        for (int j = 0; j < board[0].size(); j++) {
            if (board[row][j] == c) {
                return false;
            }
        }
        int brow = row / 3 * 3;
        int bcol = col / 3 * 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[brow + i][bcol + j] == c)
                    return false;
        return true;
    }
};

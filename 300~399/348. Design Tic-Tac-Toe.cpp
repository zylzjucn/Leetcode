class TicTacToe {
public:
    
    int len;
    vector<int> sum_row;
    vector<int> sum_col;
    int sum_diag = 0;
    int sum_antidiag = 0;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        sum_row.resize(n, 0);
        sum_col.resize(n, 0);
        len = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (player == 1) {
            sum_row[row]++;
            sum_col[col]++;
            if (row == col)
                sum_diag++;
            if (row + col == len - 1)
                sum_antidiag++;
            if (sum_row[row] == len || sum_col[col] == len || sum_diag == len || sum_antidiag == len)
                return 1;
        }
        else if (player == 2) {
            sum_row[row]--;
            sum_col[col]--;
            if (row == col)
                sum_diag--;
            if (row + col == len - 1)
                sum_antidiag--;
            if (sum_row[row] == -len || sum_col[col] == -len || sum_diag == -len || sum_antidiag == -len)
                return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

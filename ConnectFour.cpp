// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <limits.h>
#include <queue>

using namespace std;

class ConnectFour {
private:
    vector<vector<string>> board;
    int count;
    vector<int> cols;
    
public:
    ConnectFour() : board(6, vector<string>(7, " ")), count(0), cols(7, 5) {}
    
    // row: 6
    // col: 7
    
    int CheckConsecutivePieces(int i, int j, string player, int di, int dj) {
        int res = 0;
        while (true) {
            i += di;
            j += dj;
            if (i >= 6 || i < 0 || j >= 7 || j < 0 || board[i][j] != player) {
                break;
            }
            res++;
        }
        return res;
    }
    
    bool CheckStatus(int i, int j, string player) {
        if (CheckConsecutivePieces(i, j, player, 1, 0) + CheckConsecutivePieces(i, j, player, -1, 0) >= 3) {
            return true;
        }
        if (CheckConsecutivePieces(i, j, player, 0, 1) + CheckConsecutivePieces(i, j, player, 0, -1) >= 3) {
            return true;
        }
        if (CheckConsecutivePieces(i, j, player, 1, 1) + CheckConsecutivePieces(i, j, player, -1, -1) >= 3) {
            return true;
        }
        if (CheckConsecutivePieces(i, j, player, 1, -1) + CheckConsecutivePieces(i, j, player, -1, 1) >= 3) {
            return true;
        }
        return false;
    }
    
    string InsertPiece(string player, int j) {
        if (j < 0 || j >= 7) {
            return "Error: Invalid column.";
        }
        if (cols[j] == -1) {
            return "Error: Can not insert here as this column is full.";
        }
        int i = cols[j];
        cols[j]--;
        board[i][j] = player;
        count++;
        
        if (count == 42) {
            return "Draw";
        }
        return CheckStatus(i, j, player) ? player : "Pending";
    }
    
    void PrintCurrentBoard() {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << "|" << board[i][j];
            }
            cout << "|" << endl;
        }
        cout << endl;
    }
};

int main() {

    ConnectFour connect_four;
    cout << connect_four.InsertPiece("a", 0) << endl;
    cout << connect_four.InsertPiece("b", 1) << endl;
    cout << connect_four.InsertPiece("a", 1) << endl;
    cout << connect_four.InsertPiece("b", 2) << endl;
    cout << connect_four.InsertPiece("a", 3) << endl;
    cout << connect_four.InsertPiece("b", 2) << endl;
    cout << connect_four.InsertPiece("a", 2) << endl;
    cout << connect_four.InsertPiece("b", 3) << endl;
    cout << connect_four.InsertPiece("a", 3) << endl;
    cout << connect_four.InsertPiece("b", 4) << endl;
    cout << connect_four.InsertPiece("a", 3) << endl;
    connect_four.PrintCurrentBoard();
    
    return 0;
}

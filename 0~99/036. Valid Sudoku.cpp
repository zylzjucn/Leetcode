class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> s;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    string sr = "r";
                    sr.append(1, c).append(1, i + '0');
                    string sc = "c";
                    sc.append(1, c).append(1, j + '0');
                    string sb = "b";
                    sb.append(1, c).append(1, (3 * (i / 3) + j / 3) + '0');
                    if (s.find(sr) != s.end() || s.find(sc) != s.end() || s.find(sb) != s.end())
                        return false;
                    s.insert(sr);
                    s.insert(sc);
                    s.insert(sb);
                }
            }
        return true;
    }
};

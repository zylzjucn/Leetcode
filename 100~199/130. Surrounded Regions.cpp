class Solution {
public:
    void solve(vector<vector<char>>& m) {
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                if ((i == 0 || i == m.size() - 1 || j == 0 || j == m[0].size() - 1) && m[i][j] == 'O')
                    find(m, i, j);
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                if (m[i][j] == 'O')
                    m[i][j] = 'X';
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                if (m[i][j] == 'A')
                    m[i][j] = 'O';
    }
    void find(vector<vector<char>>& m, int i, int j) {
        m[i][j] = 'A';
        if (i > 0 && m[i - 1][j] == 'O')
            find(m, i - 1, j);
        if (i < m.size() - 1 && m[i + 1][j] == 'O')
            find(m, i + 1, j);
        if (j > 0 && m[i][j - 1] == 'O')
            find(m, i, j - 1);
        if (j < m[0].size() - 1 && m[i][j + 1] == 'O')
            find(m, i, j + 1);
    }
};

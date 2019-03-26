class Solution {
public:
    void gameOfLife(vector<vector<int>>& m) {
        int a = m.size();
        if (!a)
            return;
        int b = m[0].size();
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++) {
                int val = 0;
                for (int row = max(0, i - 1); row <= min(a - 1, i + 1); row++)
                    for (int col = max(0, j - 1); col <= min(b - 1, j + 1); col++)
                        val += m[row][col] % 2;
                val -= m[i][j];
                if (val == 3 || (val == 2 && m[i][j] == 1))
                    m[i][j] += 2;
            }
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                m[i][j] >>= 1;
    }
};

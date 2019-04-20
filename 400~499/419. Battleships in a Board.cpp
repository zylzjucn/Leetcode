class Solution {
public:
    int countBattleships(vector<vector<char>>& m) {
        int res = m.size() == 0 || m[0].size() == 0 || m[0][0] != 'X' ? 0 : 1;
        for (int j = 1; j < m[0].size(); j++)
            if (m[0][j] == 'X' && m[0][j - 1] != 'X')
                res++;
        for (int i = 1; i < m.size(); i++)
            if (m[i][0] == 'X' && m[i - 1][0] != 'X')
                res++;
        for (int i = 1; i < m.size(); i++)
            for (int j = 1; j < m[0].size(); j++)
                if (m[i][j] == 'X' && m[i][j - 1] != 'X' && m[i - 1][j] != 'X')
                    res++;
        return res;
    }
};

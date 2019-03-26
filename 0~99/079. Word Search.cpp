class Solution {
public:
    bool exist(vector<vector<char>>& m, string s) {
        bool res = false;
        int i = 0;
        vector<vector<int>> v(m.size(), vector<int> (m[0].size()));
        for (int row = 0; row < m.size(); row++) 
            for (int col = 0; col < m[0].size(); col++)
                if (m[row][col] == s[0])
                    find(m, v, res, s, i, row, col);
        return res;
    }
    
    void find(vector<vector<char>>& m, vector<vector<int>>& v, bool &res, string &s, int &i, int row, int col) {
        v[row][col] = 1;
        i++;
        if (i == s.length()) {
            res = true;
            return;
        }
        if (res == false)
            if (row > 0 && m[row - 1][col] == s[i] && v[row - 1][col] == 0)
                find(m, v, res, s, i, row - 1, col); 
        if (res == false)
            if (col > 0 && m[row][col - 1] == s[i] && v[row][col - 1] == 0)
                find(m, v, res, s, i, row, col - 1); 
        if (res == false)
            if (row < m.size() - 1 && m[row + 1][col] == s[i] && v[row + 1][col] == 0)
                find(m, v, res, s, i, row + 1, col); 
        if (res == false)
            if (col < m[0].size() && m[row][col + 1] == s[i] && v[row][col + 1] == 0)
                find(m, v, res, s, i, row, col + 1);
        i--;
        v[row][col] = 0;
    }
};

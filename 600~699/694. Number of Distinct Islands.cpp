class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& m) {
        unordered_set<string> s;
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[0].size(); j++) {
                if (m[i][j] == 1) {
                    string str;
                    find(m, i, j, str);
                    s.insert(str);
                }
            }
        }
        return s.size();
    }
    
    void find(vector<vector<int>>& m, int i, int j, string& str) {
        m[i][j] = 0;
        if (i > 0 && m[i - 1][j] == 1) {
            str.append("u");
            find(m, i - 1, j, str);
        }
        if (i < m.size() - 1 && m[i + 1][j] == 1) {
            str.append("d");
            find(m, i + 1, j, str);
        }
        if (j > 0 && m[i][j - 1] == 1) {
            str.append("l");
            find(m, i, j - 1, str);
        }
        if (j < m[0].size() - 1 && m[i][j + 1] == 1) {
            str.append("r");
            find(m, i, j + 1, str);
        }
        str.append("b");
    }
};

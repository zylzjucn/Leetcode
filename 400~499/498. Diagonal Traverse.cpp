class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& m) {
        vector<int> res;
        int row = m.size();
        if (row == 0)
            return res;
        int col = m[0].size();
        int i = 0;
        int j = 0;
        bool flag = true;
        while (i < row && j < col) {
            res.push_back(m[i][j]);
            if (flag && j == col - 1)
                i++;
            else if (flag && i == 0)
                j++;
            else if (!flag && i == row - 1)
                j++;
            else if (!flag && j == 0)
                i++;
            else {
                if (flag)
                    i--, j++;
                else
                    i++, j--;
                continue;
            }
            flag = !flag;
        }
        return res;
    }
};

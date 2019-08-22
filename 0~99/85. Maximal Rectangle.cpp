class Solution {
public:
    int maximalRectangle(vector<vector<char>>& m) {
        int res = 0;
        int row = m.size();
        if (row == 0)
            return 0;
        int col = m[0].size();
        vector<int> left(col);
        vector<int> right(col, col);
        vector<int> h(col);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (m[i][j] == '1')
                    h[j] = i == 0 ? 1 : h[j] + 1;
                else
                    h[j] = 0;
            }
            int curleft = 0;
            for (int j = 0; j < col; j++) {
                if (m[i][j] == '1')
                    left[j] = max(curleft, left[j]);
                else {
                    curleft = j + 1;
                    left[j] = 0;
                }
            }
            int curright = col;
            for (int j = col - 1; j >= 0; j--) {
                if (m[i][j] == '1')
                    right[j] = min(curright, right[j]);
                else {
                    curright = j;
                    right[j] = col;
                }
            }
            for (int j = 0; j < col; j++) {
                if (m[i][j] == '1')
                    res = max(res, h[j] * (right[j] - left[j]));
            }
        }
        return res;
    }
};

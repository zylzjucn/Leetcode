class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        if (!v.size() || !v[0].size())
            return false;
        int row = v.size();
        int col = v[0].size();
        int start = 0, end = row - 1, i = (start + end) / 2;
        while (start < end) {
            if (v[i][col - 1] < t)
                start = i + 1;
            else if (v[i][0] > t)
                end = i - 1;
            else
                break;
            i = (start + end) / 2;
        }
        start = 0;
        end = col - 1;
        int j = (start + end) / 2;
        while (start < end) {
            if (v[i][j] < t)
                start = j + 1;
            else if (v[i][j] > t)
                end = j - 1;
            else
                return true;
            j = (start + end) / 2;
        }
        return v[i][j] == t;
    }
};

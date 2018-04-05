class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int i = m.size() - 1, j = 0;
        while (i >= 0 && j < m[0].size()) {
            if (m[i][j] == target)
                return true;
            else if (m[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};

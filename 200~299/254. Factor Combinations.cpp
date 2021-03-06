class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> path;
        find(1, n, res, path);
        return res;
    }
    void find(int left, int right, vector<vector<int>> &res, vector<int> &path) {
        if (left != 1) {
            path.push_back(left);
            path.push_back(right);
            res.push_back(path);
            path.pop_back();
        }
        for (int i = max(2, left); i <= sqrt(right); i++)
            if (right % i == 0) {
                find (i, right / i, res, path);
                path.pop_back();
            }
    }
};

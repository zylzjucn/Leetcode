class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<int>> res;
        vector<int> path;
        for (int i = 0; i < n; i++)
            goDown(n, i, path, res);
        return res.size();
    }
    void goDown(int n, int col, vector<int> &path, vector<vector<int>> &res) {
        path.push_back(col); // we can push here means that it has been checked (6 or 19) so that there is no crash
        if (path.size() == n)
            res.push_back(path);
        else
            for (int i = 0; i < n; i++)
                if (!crash(i, path))  // judge the validation of the next target
                    goDown(n, i, path, res);
        path.pop_back(); // a roll-back of top down
    }
    bool crash(int col, vector<int> path) {
        for (int i = 0; i < path.size(); i++)
            if (path[i] == col || col - path[i] == path.size() - i || col - path[i] == i - path.size())
                return true;
        return false;
    }
};

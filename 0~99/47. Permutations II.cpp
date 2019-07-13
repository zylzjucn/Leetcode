class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& n) {
        vector<vector<int>> res;
        sort(n.begin(), n.end());
        build(res, n, 0);
        return res;
    }
    void build(vector<vector<int>>& res, vector<int> n, int start) {
        if (start == n.size() - 1) {
            res.push_back(n);
            return;
        }
        for (int i = start; i < n.size(); i++) {
            if (i > start && n[i] == n[start])
                continue;
            swap(n[i], n[start]);
            build(res, n, start + 1);
        }
    }
};

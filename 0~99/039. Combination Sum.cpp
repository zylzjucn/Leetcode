class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<vector<int>> res;
        vector<int> v;
        path(can, t, v, res, 0);
        return res;
    }
private:
    void path(vector<int>& can, int t, vector<int> &v, vector<vector<int>> &res, int index) {
        if (t <= 0) {
            if (t == 0)
                res.push_back(v);
        }
        else
            for (int i = index; i < can.size(); ++i) {
                v.push_back(can[i]);
                path(can, t - can[i], v, res, i);
            }
        v.pop_back();  // like a roll-back
    }
};

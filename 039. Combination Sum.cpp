class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& can, int t) {
        vector<vector<int>> res;
        vector<int> v;
        sort(can.begin(), can.end());
        path(can, t, v, res, can.size() - 1);
        return res;
    }
private:
    void path(vector<int>& can, int t, vector<int> &v, vector<vector<int>> &res, int index) {
        if (t <= 0) {
            if (t == 0)
                res.push_back(v);
            v.pop_back();
            return;
        }
        for (int i = index; i >= 0; --i) {
            v.push_back(can[i]);
            path(can, t - can[i], v, res, i);
        }
        v.pop_back();  // like a roll-back
    }
};

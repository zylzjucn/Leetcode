class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& can, int t) {
        vector<vector<int>> res;
        vector<int> v;
        sort(can.begin(), can.end());
        find(res, v, can, t, can.size() - 1);
        return res;
    }
private:
    void find(vector<vector<int>> &res, vector<int> v, vector<int> can, int t, int k) {
        if (t == 0) {
            res.push_back(v);
            return;
        }
        for (int i = k; i >= 0; i--) {
            if (t >= can[i]) {
                v.push_back(can[i]);
                find(res, v, can, t - can[i], i - 1);
                for (; i > 0 && can[i - 1] == v.back(); i--);
                v.pop_back();
            }
        }
    }
};

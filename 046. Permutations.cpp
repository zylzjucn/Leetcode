class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v = {nums[0]};
        res.push_back(v);
        for (int i = 1; i < nums.size(); ++i) {
            res = add(res, nums[i]);
        }
        return res;
    }
    vector<vector<int>> add(vector<vector<int>> before, int n) {
        int row = before.size();
        vector<vector<int>> after;
        for (int i = 0; i < row; ++i) {
            int col = before[0].size();
            for (int j = 0; j <= col; ++j) {
                vector<int> v = before[i];
                vector<int>::iterator it = v.begin() + j;
                v.insert(it, n);
                after.push_back(v);
            }
        }
        return after;
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> v;
        find(res, v, k, n, 1);
        return res;
    }
    void find(vector<vector<int>>& res, vector<int> v, int& k, int& n, int start) {
        if (k == 0 && n == 0) {
            res.push_back(v);
        }
        for (int i = start; i <= min(n, 9); i++) {
            v.push_back(i);
            k--;
            n -= i;
            find(res, v, k, n, i + 1);
            v.pop_back();
            n += i;
            k++;
        }
    }
};

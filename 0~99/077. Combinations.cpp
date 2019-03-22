class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int i = 0;
        vector<int> v(k, 0);
        vector<vector<int>> res;
        while (i >= 0) {
            v[i]++;
            if (v[i] > n)
                i--;
            else if (i == k-1)
                res.push_back(v);
            else {
                i++;
                v[i] = v[i - 1];
            }
        }
        return res;
    }
};

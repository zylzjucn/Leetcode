class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& m, int k) {
        int res = INT_MIN;
        for (int l = 0; l < m[0].size(); l++) {
            vector<int> sum(m.size(), 0);
            for (int r = l; r < m[0].size(); r++) {
                for (int i = 0; i < m.size(); i++) {
                    sum[i] += m[i][r];
                }
                set<int> s = {0}; // test
                int cur_sum = 0;
                for (int i = 0; i < m.size(); i++) {
                    cur_sum += sum[i];
                    auto it = s.lower_bound(cur_sum - k);
                    if (it != s.end())
                        res = max(res, cur_sum - *it);
                    s.insert(cur_sum);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        for (int i = 0; i < n; i++) {
            vector<int> resr(res);
            reverse(resr.begin(), resr.end());
            for (auto j : resr)
                res.push_back(j += pow(2, i));
        }
        return res;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& n) {
        vector<int> res(n.size(), 1);
        int r = 1;
        for (int i = 1; i < n.size(); i++)
            res[i] = n[i - 1] * res[i - 1];
        for (int i = n.size() - 1; i >= 0; i--) {
            res[i] *= r;
            r *= n[i];
        }
        return res;
    }
};

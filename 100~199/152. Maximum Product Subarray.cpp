class Solution {
public:
    int maxProduct(vector<int>& n) {
        int pmax = n[0];
        int pmin = n[0];
        int res = n[0];
        for (int i = 1; i < n.size(); i++) {
            if (n[i] < 0)
                swap(pmax, pmin);
            pmax = max(pmax * n[i], n[i]);
            pmin = min(pmin * n[i], n[i]);
            res = max(pmax, res);
        }
        return res;
    }
};

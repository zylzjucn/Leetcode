class Solution {
public:
    int findLengthOfLCIS(vector<int>& n) {
        if (n.size() == 0) {
            return 0;
        }
        int l = 1, lmax = 1;
        for (int i = 1; i < n.size(); i++) {
            if (n[i] > n[i-1])
                l++;
            else {
                lmax = max(lmax, l);
                l = 1;
            }
        }
        lmax = max(lmax, l);
        return lmax;
    }
};

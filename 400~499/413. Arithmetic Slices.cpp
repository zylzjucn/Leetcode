class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& n) {
        int res = 0;
        int len = 0;
        for (int i = 2; i < n.size(); i++) {
            if (n[i] - n[i - 1] == n[i - 1] - n[i - 2])
                len++;
            else {
                res += len * (len + 1) / 2;
                len = 0;
            }
        }
        res += len * (len + 1) / 2;
        len = 0;
        return res;
    }
};

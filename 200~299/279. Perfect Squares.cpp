class Solution {
public:
    int numSquares(int n) {
        int res = n;
        int cur = 0;
        find(n, cur, res);
        return res;
    }
    void find(int n, int &cur, int &res) {
        if (n == 0)
            res = min(res, cur);
        for (int i = sqrt(n); i > 0; --i) {
            int k = n / (i * i);
            cur += k;
            if (cur >= res) {
                cur -= k;
                break;
            }
            find(n - k * i * i, cur, res);
            cur -= k;
        }
    }
};

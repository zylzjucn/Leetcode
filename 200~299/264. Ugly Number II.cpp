class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> res(n, 0);
        res[0] = 1;
        int t2 = 0;
        int t3 = 0;
        int t5 = 0;
        int t = 1;
        for (int i = 1; i < n; i++) {
            t = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            res[i] = t;
            if (t == res[t2] * 2)
                t2++;
            if (t == res[t3] * 3)
                t3++;
            if (t == res[t5] * 5)
                t5++;
        }
        return res.back();
    }
};

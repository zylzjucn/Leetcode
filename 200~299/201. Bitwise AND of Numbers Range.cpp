class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int t = 1;
        while (m != 0 || n != 0) {
            if (m == n)
                res += (m % 2) * t;
            t *= 2;
            m /= 2;
            n /= 2;
        }
        return res;
    }
};

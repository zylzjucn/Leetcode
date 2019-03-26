class Solution {
public:
    int countPrimes(int n) {
        if (n == 0)
            return 0;
        int notp[n] = {0};
        int res = 0;
        for (int i = 2; i < n; i++) {
            if (notp[i] == 0) {
                res++;
                for (int j = 2; i * j < n; j++)
                    notp[i * j] = 1;
            }
        }
        return res;
    }
};

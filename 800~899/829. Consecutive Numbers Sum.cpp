class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 1;
        for (int i = 2; i < sqrt(2 * N); i++) {
            int ix = N - i * (i - 1) / 2;
            if (ix < 0)
                break;
            if (ix % i == 0)
                res++;
        }
        return res;
    }
};

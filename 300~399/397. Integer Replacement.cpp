class Solution {
public:
    int integerReplacement(int n) {
        int res = 0;
        if (n == INT_MAX) {
            n /= 2;
            n++;
            res += 2;
        }
        while (n > 1) {
            if (n == 3)
                return res + 2;
            res++;
            if (n % 2 == 0)
                n /= 2;
            else if ((n - 1) % 4 == 0)
                n--;
            else
                n++;
        }
        return res;
    }
};

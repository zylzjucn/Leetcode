class Solution {
public:
    int countDigitOne(int n) {
        if (n < 1)
            return 0;
        int sum = 0, i = 1, m = n;
        while (m) {
            if (m % 10 == 0)
                sum += m / 10 * i;
            else if (m % 10 == 1)
                sum += m / 10 * i + n % i + 1;
            else
                sum += m/10 * i + i;
            m /= 10;
            i *= 10;
        }
        return sum;
    }
};

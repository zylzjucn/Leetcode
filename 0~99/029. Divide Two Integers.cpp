class Solution {
public:
    int divide(int a1, int b1) {
        int flag = 1, r = 1;
        if (!b1 || (a1 == INT_MIN && b1 == -1))
            return INT_MAX;
        long a = a1, b = b1, temp, sum = 0;
        if (a < 0) {
            flag = -flag;
            a = -a;
        }
        if (b < 0) {
            flag = -flag;
            b = -b;
        }
        while (a >= b) {
            temp = b;
            r = 1;
            while (a >= (temp << 1)) {
                temp <<= 1;
                r <<= 1;
            }
            sum += r;
            a -= temp;
        }
        return flag * sum;
    }
};

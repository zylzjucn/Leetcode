class Solution {
public:
    int addDigits(int n) {
        if (n == 0)
            return 0;
        int res = n % 9;
        return res == 0 ? 9 : res;
    }
};

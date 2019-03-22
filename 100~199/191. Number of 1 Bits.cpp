class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 0;
        while (n != 0) {
            n % 2 ? i++ : 1;
            n /= 2;
        }
        return i;
    }
};

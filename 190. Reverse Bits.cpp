class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 31;
        uint32_t m = 0;
        while(n != 0) {
            m += (n % 2) * pow(2, i);
            n /= 2;
            i--;
        }
        return m;
    }
};

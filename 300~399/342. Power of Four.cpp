class Solution {
public:
    bool isPowerOfFour(int num) {
        return num != 0 && ((int)pow(2, 30) % num == 0) && (sqrt(num) * sqrt(num) == num);
    }
};

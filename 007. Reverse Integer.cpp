class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int temp;
        int tail;
        while (x != 0) {
            tail = x % 10;
            temp = 10 * result + tail;
            if ((temp - tail)/10 != result)
                return 0;
            result = temp;
            x = x / 10;
        }
        return result;
    }
};

class Solution {
public:
    bool isPerfectSquare(int n) 
    {
        int i = -1;
        for(; n > 0; n -= i) {
            i += 2;
        }
        return n == 0;
    }
};

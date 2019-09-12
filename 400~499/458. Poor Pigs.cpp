class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int count = minutesToTest / minutesToDie + 1;
        int res = 0;
        while (pow(count, res) < buckets)
            res++;
        return res;
    }
};

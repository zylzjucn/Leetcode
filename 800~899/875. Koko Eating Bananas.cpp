class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = pow(10, 9);
        while (l < r) {
            int mid = (l + r) / 2;
            int count = 0;
            for (const auto& pile : piles)
                count += (pile - 1) / mid + 1;
            if (count > h)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int max1 = INT_MAX;
        int max2 = INT_MAX;
        for (const auto& x : nums) {
            if (x <= max1)
                max1 = x;
            else if (x <= max2)
                max2 = x;
            else
                return true;
        }
        return false;
    }
};

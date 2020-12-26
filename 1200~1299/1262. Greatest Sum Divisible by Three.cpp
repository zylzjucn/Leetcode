class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> v(3, 0);
        for (const auto& n : nums)
            for (const auto& val : vector<int>(v))
                v[(val + n) % 3] = max(v[(val + n) % 3], val + n);
        return v[0];
    }
};

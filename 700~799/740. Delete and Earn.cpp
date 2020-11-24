class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> v(10001, 0);
        for (const auto& n : nums)
            v[n]++;
        int odd = 0;
        int even = 0;
        for (int i = 1; i < v.size(); i++) {
            if (i % 2 != 0)
                odd = max(odd + v[i] * i, even);
            else
                even = max(even + v[i] * i, odd);
        }
        return max(odd, even);
    }
};

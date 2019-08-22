class Solution {
public:
    int combinationSum4(vector<int>& nums, int t) {
        sort(nums.begin(), nums.end());
        vector<unsigned int> v(t + 1, 0);
        v[0] = 1;
        for (int i = 1; i < v.size(); i++)
            for (const auto& num : nums) {
                if (i < num)
                    break;
                v[i] += v[i - num];
            }
        return v.back();
    }
};

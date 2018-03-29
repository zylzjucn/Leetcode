class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        return max(f(nums, 0, nums.size() - 1), f(nums, 1, nums.size()));
    }
    int f(vector<int>& nums, int m, int n) {
        int a = 0, b = 0, i = m;
        while (i < n) {
            if (i % 2 == 0)
                a = max(a + nums[i], b);
            else
                b = max(b + nums[i], a);
            i++;
        }
        return max(a, b);
    }
};

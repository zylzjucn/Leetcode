class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int res[n] = {0};
        int far = 0;
        for (int i = 0; i < n; i++) {
            for (int j = far + 1; j <= min(n - 1, i + nums[i]); j++)
                res[j] = res[i] + 1;
            far = max(far, i + nums[i]);  // to make sure only update once
        }
        return res[n - 1];
    }
};

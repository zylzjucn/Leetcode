class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 2; len < nums.size(); len++) {
            for (int i = 0; i + len < nums.size(); i++) {
                int j = i + len;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]);
                }
            }
        }
        return dp[0].back();
    }
};

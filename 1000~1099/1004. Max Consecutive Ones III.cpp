class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0, sum = 0, res = 0;
        while (i < nums.size()) {
            sum += nums[i++];
            while (i - j - sum > k) {
                sum -= nums[j++];
            }
            res = max(res, i - j);
        }
        return res;
    }
};

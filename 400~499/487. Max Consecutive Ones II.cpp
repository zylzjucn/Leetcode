class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        vector<int> right(nums.size(), 0);
        int res = -1;
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] == 1) {
                left[i] = ++count;
            }
            else
                count = 0;
        }
        count = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i + 1] == 1) {
                right[i] = ++count;
            }
            else
                count = 0;
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                res = max(res, left[i] + right[i] + 1);
        return res == -1 ? nums.size() : res;
    }
};

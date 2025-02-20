class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        for (; i >= 0 && nums[i] >= nums[i + 1]; i--);
        int j = i + 1;
        if (i >= 0) {
            for (; j < nums.size() && nums[j] > nums[i]; j++);
            j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

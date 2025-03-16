class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> asc, dsc;
        int res = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            while (!asc.empty() && nums[right] < asc.back()) {
                asc.pop_back();
            }
            asc.push_back(nums[right]);
            while (!dsc.empty() && nums[right] > dsc.back()) {
                dsc.pop_back();
            }
            dsc.push_back(nums[right]);
            while (!asc.empty() && !dsc.empty() && dsc.front() - asc.front() > limit) {
                if (nums[left] == asc.front()) {
                    asc.pop_front();
                }
                if (nums[left] == dsc.front()) {
                    dsc.pop_front();
                }
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};

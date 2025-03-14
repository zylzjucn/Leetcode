class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> m;
        int sum = 0;
        for (const auto& num : nums) {
            sum += num;
            m[num * 2]++;
        }
        int res = INT_MIN;
        for (const auto& num : nums) {
            if (m.count(sum - num) && (sum - num != 2 * num || m[sum - num] > 1)) {
                res = max(res, num);
            }
        }
        return res;
    }
};

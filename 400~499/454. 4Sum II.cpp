class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        int res = 0;
        for (const auto& num1 : nums1) {
            for (const auto& num2 : nums2) {
                map[num1 + num2]++;
            }
        }
        for (const auto& num3 : nums3) {
            for (const auto& num4 : nums4) {
                if (map.count(- num3 - num4)) {
                    res += map[- num3 - num4];
                }
            }
        }
        return res;
    }
};

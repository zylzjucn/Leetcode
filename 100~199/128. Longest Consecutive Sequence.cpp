class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for (const auto& num : s) {
            if (!s.count(num - 1)) {
                int len = 1;
                int val = num;
                while (s.count(val + 1)) {
                    len++;
                    val += 1;
                }
                res = max(len, res);
            }
        }
        return res;
    }
};

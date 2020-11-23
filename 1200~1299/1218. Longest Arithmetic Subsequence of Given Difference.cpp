class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> m;
        int res = 0;
        for (const auto& x : arr) {
            if (!m.count(x - difference))
                m[x] = 1;
            else
                m[x] = m[x - difference] + 1;
            res = max(res, m[x]);
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> m;
        for (const auto& num : nums) {
            m[num]++;
        }
        vector<vector<int>> res = {{}};
        for (const auto& p : m) {
            int len = res.size();
            for (int i = 0; i < len * p.second; i++) {
                vector<int> cur = res[i];
                cur.push_back(p.first);
                res.push_back(cur);
            }
        }
        return res;
    }
};

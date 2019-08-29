class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for (const auto& n : nums)
            m[n]++;
        vector<pair<int, int>> v;
        for (const auto& p : m)
            v.push_back(p);
        auto comp = [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };
        // vector<vector<int>> v;
        // for (auto it = m.begin(); it != m.end(); it++)
        //     v.push_back(*it);
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < v.size() && k > 0; i++, k--)
            res.push_back(v[i].first);
        return res;
    }
};

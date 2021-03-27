class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;
        for (const auto& word : words)
            m[word]++;
        vector<pair<string, int>> v;
        for (const auto& p : m)
            v.emplace_back(p);
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        };
        partial_sort(v.begin(), v.end(), v.begin() + k, cmp);
        for (int i = 0; i < k; i++)
            res.push_back(v[i].first);
        return res;
    }
};

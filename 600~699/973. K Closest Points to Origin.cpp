class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int, vector<int>> m;
        vector<vector<int>> res;
        for (const auto& p : points) {
            m.insert(make_pair(p[0] * p[0] + p[1] * p[1], p));
        }
        auto it = m.begin();
        while (K-- && it != m.end()) {
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};

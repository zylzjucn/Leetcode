class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> h;
        for (const auto& b : buildings) {
            h.emplace_back(b[0], b[2]);
            h.emplace_back(b[1], -b[2]);
        }
        sort(h.begin(), h.end(), [](pair<int, int> a, pair<int, int> b) {return a.first < b.first || (a.first == b.first && a.second > b.second);});
        multiset<int> s = {0};
        int cur;
        int pre = 0;
        for (const auto& p : h) {
            if (p.second > 0)
                s.insert(p.second);
            else
                s.erase(s.find(-p.second));
            cur = *s.rbegin();
            if (pre != cur) {
                res.push_back({p.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};

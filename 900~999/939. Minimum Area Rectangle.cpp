class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int res = INT_MAX;
        unordered_map<int, unordered_set<int>> m;
        for (const auto& v : points)
            m[v[0]].insert(v[1]);
        for (int i = 0; i < points.size(); i++)
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                if (m[points[i][0]].count(points[j][1]) && m[points[j][0]].count(points[i][1]))
                    res = min(res, abs((points[j][0] - points[i][0]) * (points[j][1] - points[i][1])));
            }
        return res == INT_MAX ? 0 : res;
    }
};

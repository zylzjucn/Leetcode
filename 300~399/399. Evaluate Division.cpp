class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, pair<string, double>> map;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            if (!map.count(a)) {
                map[a] = {a, 1.0};
            }
            if (!map.count(b)) {
                map[b] = {b, 1.0};
            }
            unionStrings(map, a, b, values[i]);
        }
        vector<double> res;
        for (const auto& query : queries) {
            string str_1 = query[0], str_2 = query[1];
            if (!map.count(str_1) || !map.count(str_2)) {
                res.push_back(-1.0);
                continue;
            }
            auto [parent_1, weight_1] = find(map, str_1);
            auto [parent_2, weight_2] = find(map, str_2);
            if (parent_1 != parent_2) {
                res.push_back(-1.0);
            } else {
                res.push_back(weight_1 / weight_2);
            }
        }
        return res;
    }

    void unionStrings(unordered_map<string, pair<string, double>>& map, const string& a, const string& b, double val) {
        auto [parent_a, weight_a] = find(map, a);
        auto [parent_b, weight_b] = find(map, b);
        if (parent_a != parent_b) {
            map[parent_a] = {parent_b, val * weight_b / weight_a};
        }
    }

    pair<string, double> find(unordered_map<string, pair<string, double>>& map, string cur) {
        if (cur != map[cur].first) {
            auto [parent, weight] = find(map, map[cur].first);
            map[cur] = {parent, weight * map[cur].second};
        }
        return map[cur];
    }
};

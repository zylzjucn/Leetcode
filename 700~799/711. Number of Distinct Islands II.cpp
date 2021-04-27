class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& m) {
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first < b.first || (a.first == b.first && a.second < b.second);
        };
        set<vector<pair<int, int>>> s;
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++) {
                if (m[i][j]) {
                    vector<pair<int, int>> v_original;
                    find(m, i, j, v_original);
                    vector<vector<pair<int, int>>> v_all_shape(8);
                    for (const auto& p : v_original) {
                        int i0 = p.first;
                        int j0 = p.second;
                        v_all_shape[0].emplace_back(i0, j0);
                        v_all_shape[1].emplace_back(j0, -i0);
                        v_all_shape[2].emplace_back(-i0, -j0);
                        v_all_shape[3].emplace_back(-j0, i0);
                        v_all_shape[4].emplace_back(i0, -j0);
                        v_all_shape[5].emplace_back(-i0, j0);
                        v_all_shape[6].emplace_back(j0, i0);
                        v_all_shape[7].emplace_back(-j0, -i0);
                    }
                    for (auto& v_shape : v_all_shape) {
                        sort(v_shape.begin(), v_shape.end(), cmp);
                        vector<pair<int, int>> v_cur;
                        auto po = v_shape[0];
                        for (auto& p_cur : v_shape) {
                            p_cur.first = p_cur.first - po.first;
                            p_cur.second = p_cur.second - po.second;
                        }
                    }
                    sort(v_all_shape.begin(), v_all_shape.end());
                    s.insert(v_all_shape[0]);
                }
            }
        return s.size();
    }
    
    void find(vector<vector<int>>& m, int i, int j, vector<pair<int, int>>& v) {
        if (i < 0 || i >= m.size() || j < 0 || j >= m[0].size() || m[i][j] == 0)
            return;
        v.emplace_back(i, j);
        m[i][j] = 0;
        find(m, i - 1, j, v);
        find(m, i + 1, j, v);
        find(m, i, j - 1, v);
        find(m, i, j + 1, v);
    }
};

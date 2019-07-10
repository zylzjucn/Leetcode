class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        auto cmp = [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
            return a.first > b.first;
        };
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype (cmp)> p(cmp);
        p.push(make_pair(m[0][0], make_pair(0, 0)));
        while (--k > 0) {
            int i = p.top().second.first;
            int j = p.top().second.second;
            p.pop();
            if (j < m[0].size() - 1)
                p.push(make_pair(m[i][j + 1], make_pair(i, j + 1)));
            if (j == 0 && i < m.size() - 1)
                p.push(make_pair(m[i + 1][j], make_pair(i + 1, j)));
        }
        return p.top().first;
    }
};

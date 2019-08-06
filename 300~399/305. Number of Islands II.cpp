class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> res;
        int count = 0;
        vector<int> leader(m * n, -1);
        for (const auto& v : positions) {
            int i = v[0] * n + v[1];
            if (leader[i] != -1) {
                res.push_back(count);
                continue;
            }
            leader[i] = i;
            count++;
            for (const auto& p : dir) {
                int x = v[0] + p.first;
                int y = v[1] + p.second;
                int newi = x * n + y;
                if (x < 0 || x >= m || y < 0 || y >= n || leader[newi] == -1)
                    continue;
                int newroot = find(leader, newi);
                if (newroot != leader[i]) {
                    leader[i] = newroot;
                    i = newroot;
                    count--;
                }
            }
            res.push_back(count);
        }
        return res;
    }
    
private:
    int find(vector<int>& leader, int x) {
        int res = x;
        while (res != leader[res]) {
            leader[res] = leader[leader[res]];
            res = leader[res];
        }
        leader[x] = res;
        return res;
    }
};

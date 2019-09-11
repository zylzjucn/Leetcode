class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int res = stones.size();
        unordered_map<int, int> m;
        for (const auto& v : stones) {
            uni(v[0], v[1] + 10000, m, res);
        }
        return res;
    }
    
    int find(int x, unordered_map<int, int>& m, int& res) {
        if (!m.count(x)) {
            m[x] = x;
            res--;
        }
        if (m[x] != x)
            m[x] = find(m[x], m, res);
        return m[x];
    }
    
    void uni(int x, int y, unordered_map<int, int>& m, int& res) {
        int fx = find(x, m, res);
        int fy = find(y, m, res);
        if (fx != fy) {
            res++;
            m[fx] = fy;
        }
    }
};



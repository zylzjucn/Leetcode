class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& v) {
        vector<int> u(n, -1);
        for (int i = 0; i < v.size(); i++) {
            int p = find(u, v[i].first);
            int q = find(u, v[i].second);
            if (p == q)
                return false;
            u[q] = p;
        }
        return n - 1 == v.size();
    }
    int find(vector<int>& u, int t) {
        if (u[t] == -1)
            return t;
        return find(u, u[t]);
    }
};

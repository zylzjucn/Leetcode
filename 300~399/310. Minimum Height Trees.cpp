class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            vector<int> res = {0};
            return res;
        }
        vector<unordered_set<int>> v(n);
        vector<int> q;
        for (const auto& p : edges) {
            v[p[0]].insert(p[1]);
            v[p[1]].insert(p[0]);
        }
        q.push_back(-1);
        for (int i = 0; i < n; i++)
            if (v[i].size() == 1)
                q.push_back(i);
        n++;
        int i = 0;
        while (1) {
            if (q[i] == -1) {
                if (q.size() == n)
                    break;
                i++;
                n++;
                q.push_back(-1);
                continue;
            }
            int x = *v[q[i]].begin();
            v[x].erase(q[i]);
            if (v[x].size() == 1)
                q.push_back(x);
            i++;
        }
        vector<int> res(q.begin() + i + 1, q.end());
        return res;
    }
};

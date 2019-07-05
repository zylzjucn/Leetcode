class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> v;
        vector<vector<int>> vv(n, v);
        vector<int> count(n, 0);
        
        for (auto& p : pre) {
            vv[p[1]].push_back(p[0]);
            count[p[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (count[i] == 0)
                q.push(i);
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            n--;
            for (auto& i : vv[cur]) {
                count[i]--;
                if (count[i] == 0) {
                    q.push(i);
                }
            }
        }
        return n == 0;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, unordered_map<int, int>> m;
        for (const auto& v : times)
            m[v[0]].emplace(v[1], v[2]);
        vector<int> v(N + 1, INT_MAX);
        v[K] = 0;
        v[0] = 0;
        vector<bool> used(N + 1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, K);
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();
            if (used[p.second])
                continue;
            used[p.second] = true;
            v[p.second] = p.first;
            for (const auto& pi : m[p.second]) {
                if (v[pi.first] > pi.second + p.first) {
                    v[pi.first] = pi.second + p.first;
                    pq.emplace(v[pi.first], pi.first);
                }
            }
        }
        int res = *max_element(v.begin(), v.end());
        return res == INT_MAX ? -1 : res;
    }
};

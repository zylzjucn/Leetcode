class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<vector<int>>> edges(n);
        for (const auto& flight : flights)
            edges[flight[0]].push_back({flight[1], flight[2]});
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, -1});
        while (!pq.empty()) {
            vector<int> v = pq.top();
            pq.pop();
            int cur_cost = v[0];
            int cur_node = v[1];
            int cur_stops = v[2];
            if (cur_node == dst)
                return cur_cost;
            if (cur_stops >= K)
                continue;
            for (const auto edge: edges[cur_node])
                pq.push({cur_cost + edge[1], edge[0], cur_stops + 1});
        }
        return -1;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // int res = INT_MAX;
        vector<vector<vector<int>>> edges(n);
        for (const auto& flight : flights)
            edges[flight[0]].push_back({flight[1], flight[2]});
        vector<int> mem(n, INT_MAX);
        mem[src] = 0;
        queue<pair<int, int>> q;
        q.emplace(src, 0);
        q.emplace(-1, -1);
        int stops = 0;
        while (q.size() > 1) {
            if (stops > K)
                break;
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == -1) {
                stops++;
                q.emplace(-1, -1);
                continue;
            }
            // if (cur.first == dst)
            //     res = min(res, cur.second);
            for (const auto& v : edges[cur.first]) {
                // to be optimized
                if (cur.second + v[1] < mem[v[0]]) {
                    q.emplace(v[0], cur.second + v[1]);
                    mem[v[0]] = cur.second + v[1];
                }
            }
        }
        return mem[dst] == INT_MAX ? -1 : mem[dst];
    }
};

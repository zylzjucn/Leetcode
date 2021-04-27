class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target)
            return 0;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < routes.size(); i++) {
            for (const auto& stop : routes[i])
                m[stop].push_back(i);
        }
        unordered_set<int> seen_stop;
        unordered_set<int> seen_route;
        seen_stop.insert(source);
        queue<int> q;
        q.push(source);
        q.push(-1);
        int len = 1;
        while (q.size() > 1) {
            int stop = q.front();
            q.pop();
            if (stop == -1) {
                q.push(stop);
                len++;
            }
            for (const auto& route : m[stop]) {
                if (seen_route.count(route))
                    continue;
                seen_route.insert(route);
                for (const auto& next_stop : routes[route]) {
                    if (next_stop == target)
                        return len;
                    if (seen_stop.count(next_stop))
                        continue;
                    seen_stop.insert(next_stop);
                    q.push(next_stop);
                }
            }
        }
        return -1;
    }
};

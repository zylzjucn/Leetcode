582. Kill Process
class Solution {
public:
    vector<int> killProcess(vector<int>& selves, vector<int>& parents, int kill) {
        vector<int> res;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < parents.size(); i++)
            m[parents[i]].push_back(selves[i]);
        queue<int> q;
        q.push(kill);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            if (m.count(cur))
                for (const auto& child : m[cur])
                    q.push(child);
        }
        return res;
    }
};

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (const auto& v : tickets)
            m[v[0]].insert(v[1]);
        visit(res, m, "JFK");
        return vector<string>(res.rbegin(), res.rend());
    }
    
    void visit(vector<string>& res, unordered_map<string, multiset<string>>& m, string port) {
        while (m[port].size()) {
            string next = *m[port].begin();
            m[port].erase(m[port].begin());
            visit(res, m, next);
            // m[port].insert(next);
        }
        res.push_back(port);
    }
};

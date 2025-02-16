class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (const auto& ticket : tickets) {
            m[ticket[0]].insert(ticket[1]);
        }
        vector<string> res;
        buildItinerary(m, res, "JFK");
        return vector<string>(res.rbegin(), res.rend());
    }

    void buildItinerary(unordered_map<string, multiset<string>>& m, vector<string>& res, string port) {
        while (!m[port].empty()) {
            string next = *m[port].begin();
            m[port].erase(m[port].begin());
            buildItinerary(m, res, next);
        }
        res.push_back(port);
    }
};

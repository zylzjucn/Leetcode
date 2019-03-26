class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& str) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (const auto& s : str) {
            int dist = s[0] - 'a';
            string t;
            for (const char& c : s)
                t.append(1, c - dist < 'a' ? c - dist + 26 : c - dist);
            if (m.find(t) == m.end()) {
                vector<string> v;
                v.push_back(s);
                m[t] = v;
            }
            else
                m[t].push_back(s);
        }
        for (const auto& p : m)
            res.push_back(p.second);
        return res;
    }
};

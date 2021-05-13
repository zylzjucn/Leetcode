class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> m;
        for (const auto& s : cpdomains) {
            int i = 0;
            while (i < s.length()) {
                for (; s[i] != ' '; i++);
                int cur = stoi(s.substr(0, i));
                i++;
                m[s.substr(i)] += cur;
                for (; i < s.length(); i++)
                    if (s[i] == '.')
                        m[s.substr(i + 1)] += cur;
            }
        }
        vector<string> res;
        for (const auto& p : m)
            res.push_back(to_string(p.second) + " " + p.first);
        return res;
    }
};

class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, int>> v;
        for (int i = 0; i < indexes.size(); i++) {
            v.emplace_back(indexes[i], i);
        }
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        };
        sort(v.begin(), v.end(), cmp);
        for (const auto& p : v) {
            int pos = p.first;
            int i = p.second;
            string source = sources[i];
            string target = targets[i];
            if (source == s.substr(pos, source.length())) {
                s = s.substr(0, pos) + target + s.substr(pos + source.length());
            }
        }
        return s;
    }
};

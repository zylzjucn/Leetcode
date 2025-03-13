class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> v;
        for (int i = 0; i < s.length(); i++) {
            if (!v.empty() && v.back().first == s[i]) {
                v.back().second++;
            } else {
                v.emplace_back(s[i], 1);
            }
            if (v.back().second == k) {
                v.pop_back();
            }
        }
        string res;
        for (const auto& p : v) {
            res.append(p.second, p.first);
        }
        return res;
    }   
};

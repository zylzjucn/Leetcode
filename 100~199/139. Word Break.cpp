class Solution {
public:
    bool wordBreak(string s, vector<string>& v) {
        unordered_set<string> set;
        vector<bool> res(s.length() + 1, false);
        res[0] = true;
        for (const auto& str : v)
            set.insert(str);
        for (int i = 0; i < s.length(); i++) {
            if (res[i]) {
                for (const auto& str : set) {
                    if (s.substr(i, str.length()) == str)
                        res[i + str.length()] = true;
                }
            }
        }
        return res.back();
    }
};

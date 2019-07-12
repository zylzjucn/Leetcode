class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> res;
        for (const auto& s : v) {
            string s1 = s;
            sort(s1.begin(), s1.end());
            m[s1].push_back(s);
        }
        for (const auto& p : m) {
            vector<string> tmp;
            for (const auto& str : p.second)
                tmp.push_back(str);
            res.push_back(tmp);
        }
        return res;
    }
};

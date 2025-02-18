class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < words.size(); i++) {
            m[string(words[i].rbegin(), words[i].rend())].push_back(i);
        }
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            for (int j = 0; j <= s.length(); j++) {
                if (m.count(s.substr(0, j)) && isPalindromeString(s, j, s.length() - 1) && j != s.length()) {
                    for (const auto& index : m[s.substr(0, j)]) {
                        if (i != index)
                            res.push_back({i, index});
                    }
                }
                if (m.count(s.substr(j)) && isPalindromeString(s, 0, j - 1)) {
                    for (const auto& index : m[s.substr(j)]) {
                        if (i != index)
                            res.push_back({index, i});
                    }
                }
            }
        }
        return res;
    }

    bool isPalindromeString(const string& s, int i, int j) {
        for (; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};

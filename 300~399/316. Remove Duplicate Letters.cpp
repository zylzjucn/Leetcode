class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> has(26, false);
        string res = "0";
        for (const auto& c : s)
            count[c - 'a']++;
        for (const auto& c : s) {
            count[c - 'a']--;
            if (has[c - 'a'])
                continue;
            while (c < res.back() && count[res.back() - 'a'] > 0) {
                has[res.back() - 'a'] = false;
                res.pop_back();
            }
            res.append(1, c);
            has[c - 'a'] = true;
        }
        return res.substr(1);
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        find(s, res, v, 0);
        return res;
    }
    void find(string s, vector<vector<string>> &res, vector<string> &v, int start) {
        if (start == s.length()) {
            res.push_back(v);
            return;
        }
        for (int i = 0; start + i < s.length(); i++)
            if (valid(s, start, start + i)) {
                v.push_back(s.substr(start, i + 1));
                find(s, res, v, start + i + 1);
                v.pop_back();              // be careful where to put it, usually in the loop
            }
    }
    bool valid(string &s, int start, int end) {
        while (start < end)
            if (s[start++] != s[end--])
                return false;
        return true;
    }
};

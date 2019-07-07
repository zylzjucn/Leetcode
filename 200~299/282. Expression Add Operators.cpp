class Solution {
public:
    vector<string> addOperators(string s, int target) {
        vector<string> res;
        find(s, target, 0, 0, 0, "", res);
        return res;
    }
    
    void find(string& s, int target, int pos, long cur, long pre, string t, vector<string>& res) {
        if (pos == s.length() && cur == target) {
            res.push_back(t);
            return;
        }
        for (int i = 1; i <= s.length() - pos; i++) {
            string tmp = s.substr(pos, i);
            if (i > 1 && tmp[0] == '0')
                continue;    //
            long a = stol(tmp);
            if (pos == 0) {
                find(s, target, i, a, a, tmp, res);
                continue;
            }
            find(s, target, pos + i, cur + a, a, t + "+" + tmp, res);
            find(s, target, pos + i, cur - a, -a, t + "-" + tmp, res);
            find(s, target, pos + i, cur - pre + pre * a, pre * a, t + "*" + tmp, res);
        }
    }
};

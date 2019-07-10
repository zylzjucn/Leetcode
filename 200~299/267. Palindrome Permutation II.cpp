class Solution {
public:
    void build(vector<string> & res, string& s, unordered_map<char, int>& m, int count) {
        if (count < 2) {
            string t = s;
            reverse(t.begin(), t.end());
            if (count % 2 == 0)
                res.push_back(t + s);
            else
                res.push_back(t + s.substr(1));
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second < 2)
                continue;
            s.append(1, it->first);
            it->second -= 2;
            build(res, s, m, count - 2);
            it->second += 2;
            s.pop_back();
        }
    }

    vector<string> generatePalindromes(string str) {
        vector<string> res;
        unordered_map<char, int> m;
        for (char c : str)
            m[c]++;
        char odd = '#';
        for (auto p : m) {
            if (p.second % 2 == 1) {
                if (odd != '#')
                    return res;
                else
                    odd = p.first;
            }
        }
        string s;
        int count = str.length();
        if (str.length() % 2 == 1)
            s.append(1, odd);
        build(res, s, m, count);
        return res;
    }
};

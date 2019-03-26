class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& v) {
        vector<int> res;
        if (s.length() == 0 || v.size() == 0)
            return res;
        map<string, int> a;
        map<string, int> b;
        int l = v[0].length();
        int len = v.size();
        for (int i = 0; i < v.size(); i++)
            b[v[i]]++;
        for (int i = 0; i < s.length() - l * len + 1; i++) {
            int j = 0;
            for (; j < len; j++) {
                string t = s.substr(i + j * l, l);
                a[t]++;
                if (a[t] > b[t])
                    break;
            }
            if (j == len)
                res.push_back(i);
            a.clear();
        }
        return res;
    }
};

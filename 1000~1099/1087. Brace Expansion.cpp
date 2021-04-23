class Solution {
public:
    vector<string> expand(string str) {
        vector<string> res;
        vector<string> v;
        bool flag = 0;
        string s;
        for (const auto& c : str) {
            if (c == '{')
                flag = 1;
            else if (c == '}') {
                flag = 0;
                v.push_back(s);
                s.clear();
            }
                
            else if (isalpha(c)) {
                if (flag == 0) {
                    s.append(1, c);
                    v.push_back(s);
                    s.clear();
                }
                else {
                    s.append(1, c);
                }
            }
        }
        queue<string> q;
        for (auto& s : v)
            sort(s.begin(), s.end());
        for (const auto& c : v[0]) {
            string tmp;
            tmp.append(1, c);
            q.push(tmp);
        }
        q.push("");
        int i = 1;
        while (i < v.size()) {
            string s0 = q.front();
            q.pop();
            if (s0.length() == 0) {
                q.push("");
                i++;
            }
            else {
                for (const auto& c : v[i]) {
                    q.push(s0 + c);
                }
            }
        }
        while (q.size() > 1) {
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};












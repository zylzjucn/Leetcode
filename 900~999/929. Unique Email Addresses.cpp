class Solution {
public:
    int numUniqueEmails(vector<string>& v) {
        set<string> res;
        for (int i = 0; i < v.size(); i++) {
            string s;
            int j = 0;
            for (; v[i][j] != '@'; j++) {
                if (v[i][j] == '.')
                    continue;
                else if (v[i][j] == '+')
                    break;
                else
                    s.push_back(v[i][j]);
            }
            for (; v[i][j] != '@'; j++);
            s.append(v[i].substr(j));
            res.insert(s);
        }
        return res.size();
    }
};

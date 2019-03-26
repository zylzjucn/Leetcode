class Solution {
public:
    int ladderLength(string a, string b, vector<string>& v) {
        unordered_set<string> s;
        int res = 1;
        for (const auto& str : v)
            s.insert(str);
        queue<string> q;
        q.push(a);
        s.erase(a);
        q.push("");
        while (q.size() > 1) {
            if (q.front() == "") {
                res++;
                q.push("");
            }
            else {
                if (q.front() == b)
                    return res;
                auto it = s.begin();
                while (it != s.end()){
                    if (close(q.front(), *it)) {
                        string tmp = *it;
                        it++;
                        q.push(tmp);
                        s.erase(tmp);
                    }
                    else
                        it++;
                }
            }
            q.pop();
        }
        return 0;
    }
    bool close(string a, string b) {
        int dif = 0;
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
                dif++;
        return dif == 1;
    }
};

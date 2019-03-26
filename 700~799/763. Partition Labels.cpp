class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        map<char, int> m;
        for (int i = 0; i < s.length(); i++)
            m[s[i]]++;
        set<char> s1;
        int tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            m[s[i]]--;
            if (m[s[i]] != 0)
                s1.insert(s[i]);
            else
                s1.erase(s[i]);
            if (s1.size() == 0) {
                res.push_back(i + 1 - tmp);
                tmp += res.back();
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& n) {
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        map<int, int> m;
        for (int i = 0; i < n.size(); ++i) {
            if (m.find(n[i]) == m.end())
                m[n[i]] = 1;
            else
                m[n[i]]++;
        }
        for (map<int, int> :: iterator it = m.begin(); it != m.end(); ++it) {
            int l = res.size();
            for (int i = 0; i < l * it->second; ++i) {
                v = res[i];
                v.push_back(it->first);
                res.push_back(v);
            }
        }
        return res;
    }
};

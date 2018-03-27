class Solution {
public:
    vector<vector<int>> subsets(vector<int>& n) {
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        for (int i = 0; i < n.size(); i++) {
            int len = res.size();
            for (int j = 0; j < len; j++) {
                if (res[j].size() == 0)
                    v.clear();
                else
                    v = res[j];
                v.push_back(n[i]);
                res.push_back(v);
            }
        }
        return res;
    }
};

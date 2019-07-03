class Solution {
public:
    int candy(vector<int>& v) {
        if (v.size() < 2)
            return v.size();
        int result = 0;
        vector<int> res(v.size(), -1);
        for (int i = 1; i < v.size() - 1; i++)
            if (v[i] <= v[i - 1] && v[i] <= v[i + 1])
                res[i] = 1;
        if (v.size() >= 2) {
            if (v[0] <= v[1])
                res[0] = 1;
            if (v[v.size() - 1] <= v[v.size() - 2])
                res[v.size() - 1] = 1;
        }
        int level = v.size();
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == 1)
                level = 1;
            else if (i > 0 && v[i] > v[i - 1]) {
                level++;
                res[i] = max(res[i], level);
            }
        }
        for (int i = res.size() - 1; i >= 0; i--) {
            if (res[i] == 1)
                level = 1;
            else if (i < v.size() - 1 && v[i] > v[i + 1]) {
                level++;
                res[i] = max(res[i], level);
            }
            result += res[i];
        }
        return result;
    }
};

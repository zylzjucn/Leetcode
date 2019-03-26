class Solution {
public:
    int totalFruit(vector<int>& v) {
        map<int, int> m;
        int start = 0;
        int end = 0;
        int res = 0;
        while (end < v.size()) {
            if (m.size() <= 2) {
                res = max(res, end - start);
                m[v[end]]++;
                end++;   
            }
            else {
                while (m.size() > 2) {
                    if (m[v[start]] == 1)
                        m.erase(v[start]);
                    else
                        m[v[start]]--;
                    start++;
                }
            }
        }
        if (m.size() <= 2)
            res = max(res, end - start);
        return res;
    }
};

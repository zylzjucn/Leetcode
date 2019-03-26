class Solution {
public:
    int leastBricks(vector<vector<int>>& v) {
        if (v.size() == 0)
            return 0;
        int len = 0;
        for (int i = 0; i < v[0].size(); i++)
            len += v[0][i];
        map<int, int> m;
        int maxlen = 0;
        for (int i = 0; i < v.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < v[i].size() - 1; j++) {
                tmp += v[i][j];
                m[tmp]++;
            }
        }
        for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
            maxlen = max(maxlen, it->second);
        return v.size() - maxlen;
    }
};

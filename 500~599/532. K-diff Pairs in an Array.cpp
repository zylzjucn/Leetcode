class Solution {
public:
    int findPairs(vector<int>& n, int t) {
        int r = 0;
        map<int, int> m;
        if (t < 0)
            return 0;
        for (int i = 0; i < n.size(); i++) {
            if (m.find(n[i]) == m.end()) {
                if (m.find(n[i] - t) != m.end())
                    r++;
                if (m.find(n[i] + t) != m.end())
                    r++;
                m[n[i]] = 1;
            }
            else if (t == 0 && m[n[i]]++ == 1)
                r++;
        }
        return r;
    }
};

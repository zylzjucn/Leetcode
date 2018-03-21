class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {
        vector<int> v = {-1, -1};
        if (n.size() == 0)
            return v;
        int i = 0, j = n.size() - 1, m;
        while (i < j) {
            m = (i + j) / 2;
            if (n[m] < t)
                i = m + 1;
            else
                j = m;
        }
        if (n[i] != t)
            return v;
        v[0] = i;
        j = n.size() - 1;
        while (i < j) {
            m = (i + j) / 2 + 1;
            if(n[m] > t)
                j = m - 1;
            else
                i = m;
        }
        v[1] = i;
        return v;
    }
};

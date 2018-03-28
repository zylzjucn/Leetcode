class Solution {
public:
    void sortColors(vector<int>& v) {
        int i, m = 0, n = v.size() - 1;
        for (i = 0; i <= n; i++) {
            while (v[i] == 2 && i < n)
                swap(v[i], v[n--]);
            while (v[i] == 0 && i > m)
                swap(v[i], v[m++]);
        }
    }
};

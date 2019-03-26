class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
        int res = 0;
        if (v.size() == 0)
            return res;
        vector<int> left(v.size(), 0);
        vector<int> right(v.size(), 0);
        left[0] = -1;
        right[v.size() - 1] = v.size();
        for (int i = 1; i < v.size(); i++) {
            int j = i - 1;
            while (j >= 0 && v[j] > v[i])
                j = left[j];
            left[i] = j;
        }
        for (int i = v.size() - 2; i >= 0; i--) {
            int j = i + 1;
            while (j < v.size() && v[j] >= v[i])
                j = right[j];
            right[i] = j;
        }
        for (int i = 0; i < v.size(); i++) {
            int l = i - left[i] - 1;
            int r = right[i] - i - 1;
            res += (sub(l + r + 1) - sub(l) - sub(r)) * v[i];
            if (res > 1000000007)
                res -= 1000000007;
        }
        return res;
    }
    int sub(int k) {
        return k * (k + 1) / 2;
    }
};

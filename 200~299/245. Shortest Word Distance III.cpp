class Solution {
public:
    int shortestWordDistance(vector<string>& v, string t1, string t2) {
        long long res = INT_MAX;
        long long i1 = res;
        long long i2 = -res;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == t1)
                i1 = i;
            if (v[i] == t2) {
                if (t1 == t2)
                    i1 = i2;
                i2 = i;
            }
            res = min(res, abs(i1 - i2));
        }
        return res;
    }
};

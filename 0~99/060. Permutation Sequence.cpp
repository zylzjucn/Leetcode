class Solution {
public:
    string getPermutation(int n, int k) {
        int i = 1, fact = 1;
        vector<int> v;
        string s;
        for (; i < n; i++)
            fact *= i;
        k--;
        for (i = 1; i <= n; i++)
            v.push_back(i);
        i = n - 1;
        while (i > 0) {
            s.push_back(v[k / fact] + '0');
            v.erase(v.begin() + k / fact);
            k %= fact;
            fact /= i;
            i--;
        }
        s.push_back(v[0] + '0');
        return s;
    }
};

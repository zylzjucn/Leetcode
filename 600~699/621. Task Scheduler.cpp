class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        unordered_map<char, int> m1;
        for (const auto& c : v)
            m1[c]++;
        unordered_map<int, int> m2;
        int maxn = 0;
        for (const auto& p : m1) {
            maxn = max(maxn, p.second);
            m2[p.second]++;
        }
        int tmp = v.size();
        return max((maxn - 1) * (n + 1) + m2[maxn], tmp);
    }
};

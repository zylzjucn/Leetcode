class Solution {
public:
    int maxSubArrayLen(vector<int>& n, int k) {
        int sum = 0;
        int res = 0;
        map<int, int> m;
        for (int i = 0; i < n.size(); i++) {
            sum += n[i];
            if (sum == k)
                res = i + 1;
            if (m.find(sum) == m.end())
                m[sum] = i;
            if (m.find(sum - k) != m.end())
                res = max(res, i - m[sum - k]);
        }
        return res;
    }
};

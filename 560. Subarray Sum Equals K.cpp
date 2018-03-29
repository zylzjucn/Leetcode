class Solution {
public:
    int subarraySum(vector<int>& n, int k) {
        int res = 0;
        int sum = 0;
        map<int, int> m;
        for (int i = 0; i < n.size(); i++) {
            sum += n[i];
            if (sum == k)
                res++;
            if (m.find(sum - k) != m.end())
                res += m[sum - k];
            if (m.find(sum) == m.end())
                m[sum] = 1;
            else
                m[sum]++;
        }
        return res;
    }
};

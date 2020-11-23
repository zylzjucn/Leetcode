class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> res;
        if (envelopes.size() == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);});
        for (const auto& envelope : envelopes) {
            auto it = lower_bound(res.begin(), res.end(), envelope[1]);
            if (it == res.end())
                res.push_back(envelope[1]);
            else
                *it = envelope[1];
        }
        return res.size();
    }
};

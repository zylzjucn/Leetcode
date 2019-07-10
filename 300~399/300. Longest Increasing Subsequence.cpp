class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (const auto& n : nums) {
            auto it = lower_bound(res.begin(), res.end(), n);
            if (it == res.end())
                res.push_back(n);
            else
                *it = n;
        }
        return res.size();
    }
};

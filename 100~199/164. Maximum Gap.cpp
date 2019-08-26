class bucket {
public:
    int bmax;
    int bmin;
    bool used;
    bucket(): bmax(INT_MIN), bmin(INT_MAX), used(false) {}
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int maxn = *max_element(nums.begin(), nums.end());
        int minn = *min_element(nums.begin(), nums.end());
        int gap = max(1, (maxn - minn) / ((int)nums.size() - 1));
        vector<bucket> v((maxn - minn) / gap + 1);
        for (const auto& n : nums) {
            int i = (n - minn) / gap;
            v[i].used = true;
            v[i].bmax = max(v[i].bmax, n);
            v[i].bmin = min(v[i].bmin, n);
        }
        int res = 0;
        int premax = v[0].bmax;
        for (const auto& b : v) {
            if (!b.used)
                continue;
            res = max(b.bmin - premax, res);
            premax = b.bmax;
        }
        return res;
    }
};

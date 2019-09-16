class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int l = 0;
        long r = 0;
        for (const auto& n :nums) {
            l = max(l, n);
            r += n;
        }
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (valid(mid, nums, m))
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
    
    bool valid(int mid, vector<int>& nums, int m) {
        int count = 1;
        long sum = 0;
        for (const auto& n : nums) {
            sum += n;
            if (sum > mid) {
                count++;
                sum = n;
                if (count > m)
                    return false;
            }
        }
        return true;
    }
};



class Solution {
public:
    int hIndex(vector<int>& v) {
        vector<int> bucket(v.size() + 1, 0);
        for (const auto& t : v) {
            if (t >= bucket.size())
                bucket[bucket.size() - 1]++;
            else
                bucket[t]++;
        }
        int count = 0;
        for (int i = bucket.size() - 1; i >= 0; i--) {
            count += bucket[i];
            if (count >= i)
                return i;
        }
        return 0;
    }
};

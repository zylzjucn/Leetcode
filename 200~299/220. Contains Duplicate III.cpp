class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& n, int k, int t) {
        set<long> s;
        for (int i = 0; i < n.size(); i++) {
            if (i > k)
                s.erase(n[i - k - 1]);
            auto it = s.lower_bound((long)n[i] - t);
            if (it != s.end() && t >= *it - n[i])  // *it <= t + n[i]   not satisfied here
                return true;
            s.insert(n[i]);
        }
        return false;
    }
};

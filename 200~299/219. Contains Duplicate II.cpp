class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& n, int k) {
        unordered_set<int> s;
        for (int i = 0; i < k && i < n.size(); i++) {
            s.insert(n[i]);
            if (s.size() <= i)
                return true;
        }
        for (int i = k; i < n.size(); i++) {
            s.insert(n[i]);
            if (s.size() <= k)
                return true;
            s.erase(n[i - k]);
        }
        return false;
    }
};

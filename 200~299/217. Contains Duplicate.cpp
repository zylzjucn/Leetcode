class Solution {
public:
    bool containsDuplicate(vector<int>& n) {
        if (n.size() == 0)
            return false;
        sort(n.begin(), n.end());
        for (int i = 0; i < n.size() - 1; ++i) {
            if (n[i] == n[i + 1])
                return true;
        }
        return false;
    }
};

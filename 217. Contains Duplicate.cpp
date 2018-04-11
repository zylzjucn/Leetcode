class Solution {
public:
    bool containsDuplicate(vector<int>& n) {
        if (n.size() == 0)
            return false;
        set<int> s;
        for (int i = 0; i < n.size(); ++i) {
            if (s.find(n[i]) != s.end())
                return true;
            s.insert(n[i]);
        }
        return false;
    }
};

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        set<int> s;
        set<int> met;
        for (const auto& x : A) {
            if (!met.count(x)) {
                met.insert(x);
                s.insert(x);
            }
            else if (!s.count(x))
                continue;
            else {
                s.erase(x);
            }
        }
        return s.size() > 0 ? *s.rbegin() : -1;
    }
};

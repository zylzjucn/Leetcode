class Solution {
public:
    int thirdMax(vector<int>& n) {
        set<int> s;
        for (int i = 0; i < n.size(); ++i)
            s.insert(n[i]);
        set<int> :: iterator it = s.end();
        if (s.size() < 3)
            return *--it;
        return *------it;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& n) {
        int res;
        set<int> s;
        for (int i = 0; i < n.size(); i++) {
            if (n[i] > 0)
                s.insert(n[i]);
        }
        int i = 1;
        for (set<int>::iterator it = s.begin(); it != s.end(); it++, i++) {
            if (*it != i)
                return i;
        }
        return i;
    }
}


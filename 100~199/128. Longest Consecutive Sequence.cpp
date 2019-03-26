class Solution {
public:
    int longestConsecutive(vector<int>& n) {
        if (n.size() == 0)
            return 0;
        int res = 0;
        int len = 0;
        set<int> s;
        for (int i = 0; i < n.size(); i++)
            s.insert(n[i]);
        set<int>::iterator it = s.begin();
        int pre = *it;
        it++;
        for (; it != s.end(); it++) {
            if (*it == pre + 1)
                len++;
            else
                len = 0;
            pre = *it;
            res = max(res, len);
        }
        return res + 1;
    }
};

class Solution {
public:
    bool canJump(vector<int>& n) {
        int i, m = 0;
        for (i = 0; i < n.size() && i <= m; i++)
            m = max(m, i + n[i]);
        return i == n.size();
    }
};

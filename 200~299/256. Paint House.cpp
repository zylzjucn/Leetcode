class Solution {
public:
    int minCost(vector<vector<int>>& m) {
        int pre0 = 0;
        int pre1 = 0;
        int pre2 = 0;
        for (int i = 0; i < m.size(); i++) {
            int cur0 = m[i][0] + min(pre1, pre2);
            int cur1 = m[i][1] + min(pre0, pre2);
            int cur2 = m[i][2] + min(pre0, pre1);
            pre0 = cur0;
            pre1 = cur1;
            pre2 = cur2;
        }
        return min(pre0, min(pre1, pre2));
    }
};

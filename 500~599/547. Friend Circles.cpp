
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        int res = n;
        int leader[n];
        for (int i = 0; i < n; i++)
            leader[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j]) {
                    int lead1 = find(i, leader);
                    int lead2 = find(j, leader);
                    if (lead1 != lead2) {
                        leader[lead2] = lead1;
                        res--;
                    }
                }
            }
        }
        return res;
    }
private:
    int find(int x, int leader[]) {
        int res = x;
        while (res != leader[res]) {
            res = leader[res];
        }
        return res;
    }
};

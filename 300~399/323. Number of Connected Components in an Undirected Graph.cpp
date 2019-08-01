class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        vector<int> leader;
        for (int i = 0; i < n; i++)
            leader.emplace_back(i);
        for (const auto& v : edges) {
            int lead0 = find(v[0], leader);
            int lead1 = find(v[1], leader);
            if (lead0 != lead1) {
                res--;
                leader[lead1] = lead0;
            }
        }
        return res;
    }
private:
    int find(int x, vector<int>& leader) {
        int res = x;
        while (res != leader[res])
            res = leader[res];
        return res;
    }
};

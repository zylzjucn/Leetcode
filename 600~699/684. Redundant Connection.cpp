class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> leader;
        vector<int> res;
        for (int i = 0; i < edges.size(); i++)
            leader.emplace_back(i);
        for (const auto& v : edges) {
            int lead0 = find(v[0] - 1, leader);
            int lead1 = find(v[1] - 1, leader);
            if (lead0 != lead1)
                leader[lead1] = lead0;
            else
                res = v;
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

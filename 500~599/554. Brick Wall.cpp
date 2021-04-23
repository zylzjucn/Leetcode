class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int max_count = 0;
        unordered_map<int, int> m;
        for (const auto& v : wall) {
            int sum = 0;
            for (int i = 0; i < v.size() - 1; i++) {
                sum += v[i];
                m[sum]++;
            }
        }
        for (const auto& p : m)
            max_count = max(max_count, p.second);
        return wall.size() - max_count;
    }
};

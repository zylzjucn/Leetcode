class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        int mindis = (height + width) * 2;
        for (const auto& nut : nuts) {
            sum += abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]);
            mindis = min(mindis, abs(nut[0] - squirrel[0]) + abs(nut[1] - squirrel[1]) - abs(nut[0] - tree[0]) - abs(nut[1] - tree[1]));
        }
        return sum * 2 + mindis;
    }
};

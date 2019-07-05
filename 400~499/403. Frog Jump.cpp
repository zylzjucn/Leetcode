class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.size() == 0)
            return true;
        unordered_map<int, unordered_set<int>> m;
        unordered_set<int> s;
        m[0] = s;
        m[0].insert(1);
        for (int i = 1; i < stones.size(); i++)
            m[stones[i]] = s;
        
        for (int i = 0; i < stones.size() - 1; i++) {
            int stone = stones[i];
            for (int step : m[stone]) {
                int reach = stone + step;
                if (reach == stones.back())
                    return true;
                if (m.count(reach)) {
                    if (step > 1)
                        m[reach].insert(step - 1);
                    m[reach].insert(step);
                    m[reach].insert(step + 1);
                }
            }
        }
        
        return false;
    }
};

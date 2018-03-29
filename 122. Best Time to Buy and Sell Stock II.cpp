class Solution {
public:
    int maxProfit(vector<int>& v) {
        int sum = 0;
        if (v.size()<2)
            return 0;
        for (int i = 0; i < v.size() - 1; i++)
            sum += max(0, v[i + 1] - v[i]);
        return sum;
    }
};

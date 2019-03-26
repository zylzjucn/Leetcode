class Solution {
public:
    int maxProfit(vector<int>& price) {
        int buy1 = INT_MIN;
        int sale1 = 0;
        int buy2 = INT_MIN;
        int sale2 = 0;
        for (auto p : price) {
            sale2 = max(sale2, buy2 + p);
            buy2 = max(buy2, sale1 - p);
            sale1 = max(sale1, buy1 + p);
            buy1 = max(buy1, -p);
        }
        return sale2;
    }
};

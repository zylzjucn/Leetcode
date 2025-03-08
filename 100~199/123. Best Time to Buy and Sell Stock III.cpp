class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low_price = prices[0];
        vector<int> left(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++) {
            int profit = max(prices[i] - low_price, 0);
            low_price = min(low_price, prices[i]);
            left[i] = max(left[i-1], profit);
        }
        vector<int> right(prices.size(), 0);
        int high_price = prices.back();
        for (int i = prices.size() - 2; i >= 0; i--) {
            int profit = max(high_price - prices[i], 0);
            high_price = max(high_price, prices[i]);
            right[i] = max(right[i+1], profit);
        }
        int max_profit = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
            max_profit = max(max_profit, left[i] + right[i+1]);
        }
        max_profit = max(max_profit, left.back());
        return max_profit;
    }
};

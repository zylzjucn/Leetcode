class Solution {
public:
    int maxProfit(vector<int>& p) {
        if (p.size() < 2)
            return 0;
        vector<int> buy;
        vector<int> sale;
        buy.push_back(-p[0]);
        buy.push_back(-p[1]);
        sale.push_back(0);
        sale.push_back(p[1] - p[0]);
        int maxbuy = max(-p[0], -p[1]);
        int maxsale = 0;
        for (int i = 2; i < p.size(); i++) {
            buy.push_back(maxsale - p[i]);
            sale.push_back(maxbuy + p[i]);
            maxbuy = max(maxbuy, buy.back());
            maxsale = max(maxsale, sale[i - 1]);
        }
        return max(maxsale, sale.back());
    }
};

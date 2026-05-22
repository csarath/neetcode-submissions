class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int prev = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i-1]) {
                profit = prices[i-1] - prev;
                res = max(profit, res);
                prev = min(prices[i], prev);
            }
        }
        profit = prices.back() - prev;
        res = max(profit, res);
        return res;
    }
};

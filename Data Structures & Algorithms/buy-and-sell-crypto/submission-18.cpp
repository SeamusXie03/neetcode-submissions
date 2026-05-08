class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];

        for (int idx = 1; idx < prices.size(); idx++) {
            maxProfit = max(prices[idx] - minPrice, maxProfit);
            minPrice = min(prices[idx], minPrice);
        }

        return maxProfit;
    }
};

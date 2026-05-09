class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = prices[0];

        for (int idx = 1; idx < prices.size(); idx++) {
            maxProfit = max(maxProfit, prices[idx] - minPrice);
            minPrice = min(minPrice, prices[idx]);
        }

        return maxProfit;
    }
};

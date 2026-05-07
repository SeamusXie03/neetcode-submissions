class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min_price = prices[0];

        for (int& cur_price : prices) {
            profit = max(cur_price - min_price, profit);
            min_price = min(cur_price, min_price);
        }

        return profit;
    }
};

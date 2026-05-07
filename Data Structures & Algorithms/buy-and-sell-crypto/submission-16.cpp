class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int min_price = prices[0];

        for (int& cur_price : prices) {
            if (cur_price < min_price) {
                min_price = cur_price;
            } else {
                profit = max(cur_price - min_price, profit);
            }
        }

        return profit;
    }
};

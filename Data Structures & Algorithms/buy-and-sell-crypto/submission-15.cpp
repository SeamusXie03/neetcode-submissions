class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l, r;

        l = 0;
        r = 1;

        int res = 0;
        for (; r < prices.size(); r++) {
            if (prices[l] < prices[r]) {
                res = max(res, prices[r] - prices[l]);
            } else {
                l = r;
            }
        }

        return res;
    }
};

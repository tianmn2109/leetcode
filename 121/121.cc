class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int minimum = prices[0];
        int ret = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] - minimum > ret)
                ret = prices[i] - minimum;
            if (prices[i] < minimum)
                minimum = prices[i];
        }
        return ret;
    }
};

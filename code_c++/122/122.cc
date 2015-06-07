class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int first = 0;
        int second = 0;
        int i = 1;
        int sum = 0;
        while (i < prices.size()) {
            while (i < prices.size() && prices[i - 1] >= prices[i])
                i ++;
            if (i == prices.size())
                break;
            first = i - 1;
            while (i < prices.size() && prices[i - 1] <= prices[i])
                i ++;
            second = i - 1;
            sum = sum + prices[second] - prices[first];
        }
        return sum;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        vector<int> f1(prices.size());
        vector<int> f2(prices.size());
        f1[0] = 0;
        int minV = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            minV = min(minV, prices[i]);
            f1[i] = max(f1[i - 1], prices[i] - minV);
        }
        int maxV = prices[prices.size() - 1];
        f2[prices.size() - 1] = 0;
        for (int i = prices.size() - 2; i >= 0; i --) {
            maxV = max(maxV, prices[i]);
            f2[i] = max(f2[i + 1], maxV - prices[i]);
        }
        int sum = 0;
        for (int i = 0; i < prices.size(); i ++) {
            int temp = f1[i] + f2[i];
            if (temp > sum)
                sum = temp;
        }
        return sum;
    }
};

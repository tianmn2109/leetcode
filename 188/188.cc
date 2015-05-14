class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        if (prices.size() / 2 < k) {
            int sum = 0;
            for (int i = 1; i < prices.size(); i ++)
                sum += max(prices[i] - prices[i - 1], 0);
            return sum;
        }
        vector<int> hold(k + 1);
        vector<int> realease(k + 1);
        for (int i = 0; i <=k; i ++) {
            realease[i] = 0;
            hold[i] = INT_MIN;
        }
        for (int i = 0; i < prices.size(); i ++) {
            int cur = prices[i];
            for (int j = k; j > 0; j --) {
                realease[j] = max(realease[j], hold[j] + cur);
                hold[j] = max(hold[j], realease[j - 1] - cur); 
            }
        }
        return realease[k];
    }
};

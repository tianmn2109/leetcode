#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxOne(vector<int> &v, int start, int end) {
        if (start >= end)
            return 0;
        int minimum = v[start];
        int ret = 0;
        for (int i = start + 1; i <= end; i ++)
        {
            if (v[i] < minimum)
                minimum = v[i];
            if (v[i] - minimum > ret)
                ret = v[i] - minimum;
        }
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> v;
        v.push_back(prices[0]);
        for (int i = 1; i < prices.size();) {
            while (i < prices.size() && prices[i] <= prices[i - 1])
                i ++;
            v.push_back(prices[i - 1]);
            if (i == prices.size())
                break;
            while (i < prices.size() && prices[i] >= prices[i - 1])
                i ++;
            v.push_back(prices[i - 1]);
            if (i == prices.size())
                break;
        }
        int start = 0;
        if (v.size() >= 2 && v[0] >= v[1])
            start ++;
        int end = v.size() - 1;
        if (v.size() >= 2 && v[end] <= v[end - 1])
            end --;
        if (end - start < 1)
            return 0;
        int sum = 0;
        for (int i = start + 1;i <= end; i += 2) {
            int temp = maxOne(v, start, i) + maxOne(v, i + 1, end);
            if (temp > sum)
                sum = temp;
        }
        return sum;
    }
};
int main()
{
	int a[] = {2,1,2,0,1};
	vector<int> p(a, a + sizeof(a) / sizeof(int));
	Solution s;
	cout << s.maxProfit(p) << endl;
	return 0;
}

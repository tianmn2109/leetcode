#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (left == right)
                return left;
            int middle = (left + right) / 2;
            if (nums[middle] < nums[middle + 1])
                left = middle + 1;
            else
                right = middle;
        }
    }
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	Solution s;	
	cout << s.findPeakElement(v) << endl;
	return 0;
}

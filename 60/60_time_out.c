/*
 * from begining to find the Kth. time limited out.
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        if (n == 0)
            return "";

        if (n == 1)
            return "1";

        vector<int> num;
        for (int i = 0; i < n; i ++)
            num.push_back(i + 1);

        while (-- k) {
            int i = n - 1; 
            for (; ;) {
                int ii = i;
                i --;
                if (i >= 0 && num[i] < num[ii]) {
                    int j = n - 1;
                    while (j >= 0 && num[j] <= num[i])
                        j --;

                    num[i] ^= num[j];
                    num[j] ^= num[i];
                    num[i] ^= num[j];
                    reverse(num.begin() + ii, num.end());
                    break;
                }

            }
        }
        string str = "";
        for (int i = 0; i < n; i ++) {
            char ch = '0' + num[i];
            str += ch;
        }
        return str;
    }
};

int main()
{
    Solution s;
    cout << s.getPermutation(3,3) << endl;
  return 0;
}

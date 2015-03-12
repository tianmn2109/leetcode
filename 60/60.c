#include <vector>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void nthPermutation(vector<int> num, string &str, int k) {
            if (num.size() == 1)
            {
                char ch = num[0] + '0';
                str += ch;
                return ;
            }
           int temp = 1;
           for (int i = 1; i <= num.size() - 1; i ++)
               temp *= i;

           int count = 0;
           while (k > temp) {
               count ++;
               k = k - temp;
           }
           char ch = num[count] + '0';
           str += ch;
           vector<int> v;
           for (int i = 0; i < num.size(); i ++)
               if (i != count)
                   v.push_back(num[i]);
           nthPermutation(v, str, k);
    }
    string getPermutation(int n, int k) {
        vector<int> num;
        string str = "";
        for (int i = 0; i < n; i ++)
            num.push_back(i + 1);
        nthPermutation(num, str, k);
        return str;
    }        
};

int main()
{
        Solution s;
	cout << s.getPermutation(2,2) << endl;
	return 0;
}

// 1
void plusone(vector<int> &digits)
{
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;
        }
        else
        {
            digits[i]++;
            return;
        }
    }
        digits[0] =1;
        digits.push_back(0);

}



// 2class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {   //未考虑前缀0的情况
        for(int i = digits.size() - 1; i >= 0; i--)   
        {
            if(digits[i] != 9)
            {
                digits[i] ++;
                break;
            }
            digits[i] = 0;
        }
        if(digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;

    }
};


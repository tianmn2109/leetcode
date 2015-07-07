class Solution {
public:
    int countDigitOne(int n) {
       if (n  < 0)
         return 0;
       long long count = 0;
       long long factor = 1;
       
       long long low = 0;
       long long cur = 0;
       long long high = 0;
       while (n / factor != 0) {
           low = n - (n / factor) * factor;
           cur = (n / factor) % 10;
           high = n / (factor * 10);
           switch (cur) {
               case 0: count += high * factor;
                       break;
               case 1: count += high * factor + low + 1;
                       break;
               default:
                      count += (high + 1) * factor;
           }
           factor *= 10;
       }
       return count;
    }
};

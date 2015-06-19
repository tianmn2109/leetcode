// 1 very nice. O(1) time.
Basic Idea:

Since sqrt(x) is composed of binary bits, I calculate sqrt(x) by deciding every bit from the most significant to least significant. Since an integer n can have O(log n) bits with each bit decided within constant time, this algorithm has time limit O(log n), actually, because an Integer can have at most 32 bits, I can also say this algorithm takes O(32)=O(1) time.

 public int sqrt(int x) {
    if(x==0)
        return 0;
    int h=0;
    while((long)(1<<h)*(long)(1<<h)<=x) // firstly, find the most significant bit
        h++;
    h--;
    int b=h-1;
    int res=(1<<h);
    while(b>=0){  // find the remaining bits
        if((long)(res | (1<<b))*(long)(res |(1<<b))<=x)
            res|=(1<<b);
        b--;
    }
    return res;
}

// 2
Instead of using fancy Newton's method, this plain binary search approach also works.

public int sqrt(int x) {
    if (x == 0)
        return 0;
    int left = 1, right = Integer.MAX_VALUE;
    while (true) {
        int mid = left + (right - left)/2;
        if (mid > x/mid) {                                  // excellent avoid overflow.
            right = mid - 1;
        } else {
            if (mid + 1 > x/(mid + 1))
                return mid;
            left = mid + 1;
        }
    }
}


// 3  Newton's Iterative Method
int sqrt(int x) {
    double ans    = x;
    double delta  = 0.0001;
    while (fabs(pow(ans, 2) - x) > delta) {
        ans = (ans + x / ans) / 2;
    }
    return ans;
}

The key point is the average result is calculate by "ans = (ans + x / ans) / 2";

For instance, when calculate sqrt(2) :

   Guess Result        Quotient                             Average Result
          1          2 / 1 = 2                            (2 + 1) / 2 = 1.5
         1.5      2 / 1.5 = 1.3333                (1.3333 + 1.5) / 2 = 1.4167
       1.4167    2 / 1.4167 = 1.4118          (1.4167 + 1.4118) / 2 = 1.4142

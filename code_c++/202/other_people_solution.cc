// 1
I see the majority of those posts use hashset to record values. Actually, we can simply adapt the Floyd Cycle detection algorithm. I believe that many people have seen this in the Linked List Cycle detection problem. The following is my code:

int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}

// 2 ??????????
Using fact all numbers in [2, 6] are not happy (and all not happy numbers end on a cycle that hits this interval):

bool isHappy(int n) {
    while(n>6){
        int next = 0;
        while(n){next+=(n%10)*(n%10); n/=10;}
        n = next;
    }
    return n==1;
}



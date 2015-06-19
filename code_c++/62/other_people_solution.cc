// 1
This problem can be trickily solved with math, the principle is simple: In total the robot should walk m + n - 2 steps, m - 1 steps to right and n - 1 steps to bottom, so all what we should do is to select which m - 1 steps to be right, therefore the problem is actually a combination problem, then we just need to calculate (n + m - 2)! / ((m - 1)! * (n - 1)!), here is the code:

class Solution {
public:
long long fab(int x, int y) {
    long long ret = 1;
    for (int i = x; i >= y && i > 0; --i) {
        ret *=i;
    }
    return ret;
}

int uniquePaths(int m, int n) {
    if (0 == m || 0 == n) {
        return 0;
    }

    int max = std::max(m, n) - 1;
    int min = std::min(m, n) - 1;

    int ret = int(fab(max + min, max + 1) / fab(min, 1));

    return ret;
}
};



// 2 similar to 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <=0 || n <= 0) return 0;
        long long res = 1;
        for(int i = n; i < m+n-1 ; i++){
            res = res * i / (i- n + 1);
        }
        return (int)res;
    }
};

The total step number should be m+n-2. This means that we have to move down for m-1 steps and move right n-1 steps to reach the definition. Then different choice number would be:

UniqueStepNum = choose (m-1) from (m+n-2) = choose (n-1) from (m+n-2)

= (m+n-2)! / [(m-1)! * (n-1)!]

= ( (m+n-2) / (m-1) ) * ( (m+n-3) / (m-2) ) * ... * (n / 1)


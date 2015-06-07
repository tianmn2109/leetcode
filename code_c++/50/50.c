/*
 * The method is implemented in the sgi stl source code.
 */
double myPow(double x, int n) {
    double result = 0.0;
    bool isNegative = false;
    if (n < 0)
    {
        isNegative = true;
        n = -n;
    }
    if (n == 0)
        return 1;
    if (x == 1)
        return 1;
    if (x == 0)
        return 0;
    if (x == -1)
        if (n % 2 ==0)
            return 1;
        else 
            return -1;
    while ((n & 1) == 0)
    {
        x = x * x;
        n >>= 1;
    }
    result = x;
    n >>= 1;
    while (n != 0)
    {
        x = x * x;
        if ((n & 1) != 0)
            result = result * x;
        n >>= 1;
    }
    if (isNegative)
        result = 1.0 / result;
    return result;
}

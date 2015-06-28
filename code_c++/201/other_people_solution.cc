// 1
Consider the bits from low to high. if n > m, the lowest bit will be 0, and then we could transfer the problem to sub-problem: rangeBitwiseAnd(m>>1, n>>1).

int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}



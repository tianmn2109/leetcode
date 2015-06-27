// 1
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
for 8 bit binary number abcdefgh, the process is as follow:

abcdefgh -> efghabcd -> ghefcdab -> hgfedcba

solution-sharing


// 2
char tb[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

uint32_t reverseBits(uint32_t n) {
        int curr = 0;
        uint32_t ret = 0;
        uint32_t msk = 0xF;
        for(int i = 0; i< 8; i++) {
            ret = ret << 4;
            curr = msk&n;
            ret |= tb[curr];
            n = n >> 4;
        }
        return ret;
}

// 3 
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for (int i = 0; i < 16; i++)
            // toggle bits when the 2 bits in a pair are different
            if ((n >> i & 1) ^ (n >> (31 - i) & 1))
                n ^= (1 << i | 1 << (31 - i));
        return n;
    }
};

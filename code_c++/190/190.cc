class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int num = 32;
        while (num --) {
            uint32_t temp = n & 0x01;
            n >>= 1;
            ret = ret << 1;
            ret = ret | temp;
        }
        return ret;
    }
};

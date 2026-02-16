class Solution {
public:
    int reverseBits(int n) {
        int temp = 0;
        for (int i = 0; i < 32; i ++){
            int currbit = n & 1;
            temp <<= 1;
            temp = temp | currbit;
            n >>= 1;
        }

        return temp;
    }
};
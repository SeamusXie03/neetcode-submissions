class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        // when n == 0, all 1 bits have been removed
        while (n != 0) {
            // remove the rightmost 1 bit
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};

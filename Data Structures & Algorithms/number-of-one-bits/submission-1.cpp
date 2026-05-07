class Solution {
public:
    int hammingWeight(uint32_t n) {
        constexpr int INT_SIZE = 32;
        int count = 0;

        for (int i = 0; i < INT_SIZE; i++) {
            if (n & 1) {
                count++;
            }

            n = n >> 1;
        }

        return count;
    }
};

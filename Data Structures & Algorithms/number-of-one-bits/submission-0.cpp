class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;

        for (auto idx = 0; idx < 32; idx++) {
            if (n % 2 == 1) {
                res++;
            }

            n = n >> 1;
        }

        return res;
    }
};

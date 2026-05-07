class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1);
        output[0] = 0;

        int lastp2 = 1;

        for (int i = 1; i <= n; i++) {
            if ((lastp2 * 2) == i) {
                lastp2 = i;
            }

            output[i] = 1 + output[i - lastp2];
        }

        return output;
    }
};

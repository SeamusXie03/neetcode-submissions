class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output(n + 1);

        for (int i = 0; i <= n; i++) {
            output[i] = hammingWeight(i);
        }

        return output;
    }

    int hammingWeight(int n) {
        int count = 0;

        while (n != 0) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};

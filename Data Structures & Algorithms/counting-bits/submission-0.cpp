class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;

        for (auto i = 0; i <= n; i++) {
            int count = 0;
            int idx = i;

            for (auto j = 0; j < sizeof(int) * 8; j++) {
                if (idx & 1) {
                    count++;
                }
                idx >>= 1;
            }

            res.push_back(count);
        }

        return res;
    }
};

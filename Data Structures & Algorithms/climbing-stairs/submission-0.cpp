class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1);
        cache[0] = 1;
        cache[1] = 1;

        for (int i = 2; i <= n; i++) {
            // Either 1 or 2 steps at a time
            cache[i] = cache[i - 2] + cache[i - 1];
        }

        return cache[n];
    }
};

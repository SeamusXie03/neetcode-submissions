class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int val = n;

        while (val != 1) {
            if (seen.contains(val)) {
                return false;
            }

            seen.insert(val);
            val = nextNum(val);
        }

        return true;
    }

    int nextNum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int lIdx = 0;
        int rIdx = s.length() - 1;

        while (lIdx < rIdx) {
            while (!isAlphanumeric(s[lIdx])) {
                lIdx++;
            }

            if (lIdx >= rIdx) {
                break;
            }

            while (!isAlphanumeric(s[rIdx])) {
                rIdx--;
            }

            if (lIdx >= rIdx) {
                break;
            }

            if (tolower(s[lIdx]) != tolower(s[rIdx])) {
                printf("Left char: %c idx: %d \n", s[lIdx], lIdx);
                printf("Right char: %c idx: %d \n", s[rIdx], rIdx);
                return false;
            }

            // Update direction
            lIdx++;
            rIdx--;
        }

        return true;
    }

    bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9');
    }
};

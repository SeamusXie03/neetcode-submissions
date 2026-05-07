class Solution {
public:
    bool isPalindrome(string s) {
        int l_ptr, r_ptr;

        l_ptr = 0;
        r_ptr = s.size() - 1;

        while (l_ptr < r_ptr) {
            while (!alphaNum(s[l_ptr]) && l_ptr < r_ptr) {
                l_ptr++;
            }

            while (!alphaNum(s[r_ptr]) && l_ptr < r_ptr) {
                r_ptr--;
            }

            if (tolower(s[l_ptr++]) != tolower(s[r_ptr--])) {
                return false;
            }
        }

        return true;
    }

    bool alphaNum (const char& c) {
        return ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
    }
};

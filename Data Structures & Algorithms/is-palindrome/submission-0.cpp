class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> front, back;

        for (int idx = 0; idx < s.size(); idx++) {
            char c = s[idx];

            if ((c >= 'a' && c <= 'z') || 
                (c >= 'A' && c <= 'Z')) {
                front.push_back(tolower(c));
            }
            
            if (c >= '0' && c <= '9') {
                front.push_back(c);
            }
        }

        for (int idx = s.size() - 1; idx >= 0; idx--) {
            char c = s[idx];

            if ((c >= 'a' && c <= 'z') || 
                (c >= 'A' && c <= 'Z')) {
                back.push_back(tolower(c));
            }
            
            if (c >= '0' && c <= '9') {
                back.push_back(c);
            }
        }

        return front == back;
    }
};

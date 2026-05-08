class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char, index
        unordered_map<char, int> charIdx;

        int l = 0;
        int length = 0;

        for (int r = 0; r < s.length(); r++) {
            if (charIdx.contains(s[r]) && charIdx[s[r]] >= l) {
                l = charIdx[s[r]] + 1;
            } 

            charIdx[s[r]] = r;
            length = max(length, r - l + 1);
        }

        return length;
    }
};

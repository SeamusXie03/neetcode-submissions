class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char, index
        unordered_map<char, int> charIdx;

        int r;
        int l = 0;
        int length = 0;

        for (r = 0; r < s.size(); r++) {
            if (charIdx.contains(s[r]) && charIdx[s[r]] >= l) {
                length = max(length, r - l);
                l = charIdx[s[r]] + 1;
            } 

            charIdx[s[r]] = r;
        }

        return max(length, r - l);
    }
};

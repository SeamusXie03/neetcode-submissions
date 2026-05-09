class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // char -> index
        unordered_map<char, int> charIdx;
        int length = 0;
        
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            if (charIdx.contains(s[r])) {
                l = max(charIdx[s[r]] + 1, l);
            }

            charIdx[s[r]] = r;
            length = max(r - l + 1, length);
        }

        return length;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seenChar;
        int maxLength = 0;

        int sIdx = 0;
        for (int eIdx = 0; eIdx < s.length(); eIdx++) {
            if (seenChar.contains(s[eIdx])) {
                sIdx = max(seenChar[s[eIdx]] + 1, sIdx);
            }
            seenChar[s[eIdx]] = eIdx;
            maxLength = max(maxLength, eIdx - sIdx + 1);
        }

        return maxLength;
    }
};

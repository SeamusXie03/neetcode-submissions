class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;

        int res;
        int left;

        left = 0;
        res = 0;

        for (int idx = 0; idx < s.size(); idx++) {
            if (seen.contains(s[idx])){
                left = max(left, seen[s[idx]] + 1);
            }

            seen[s[idx]] = idx;
            res = max(res, idx - left + 1);
        }

        return res;
    }
};

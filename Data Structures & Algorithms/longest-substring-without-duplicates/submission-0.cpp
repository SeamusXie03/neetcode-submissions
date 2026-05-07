class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;

        int wl, wr;
        wl = 0;
        int res = 0;

        for (wr = 0; wr < s.size(); wr++) {
            while (seen.contains(s[wr])) {
                seen.erase(s[wl]);
                wl++;
            }

            seen.insert(s[wr]);
            res = max(res, wr - wl + 1);
        }

        return res;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> char_map;

        int result = 0;
        int l = 0;
        int maxf = 0;

        for (int r = 0; r < s.size(); r++) {
            char_map[s[r]]++;
            maxf = max(maxf, char_map[s[r]]);

            while ((r - l + 1) - maxf > k) {
                char_map[s[l]]--;
                l++;
            }
            result = max(result, r - l + 1);
        }
        
        return result;
    }
};

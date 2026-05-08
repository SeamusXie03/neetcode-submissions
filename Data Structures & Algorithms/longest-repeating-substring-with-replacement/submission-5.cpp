class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);

        int l = 0;
        int dominantCount = 0;
        int windowSize = 0;

        for (int r = 0; r < s.size(); r++) {
            dominantCount = max(dominantCount, ++count[s[r] - 'A']);
            windowSize = r - l + 1;

            while(windowSize - dominantCount > k) {
                count[s[l] - 'A']--;
                l++;
                windowSize = r - l + 1;
            }
            
        }
        return windowSize;    
    }
};

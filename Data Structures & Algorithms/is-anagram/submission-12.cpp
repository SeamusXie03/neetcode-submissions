class Solution {
public:
    bool isAnagram(string s, string t) {
        // Evaluate at compile time
        constexpr int SIZE = 'z' - 'a' + 1;

        // Since we are only looking at lowercase English letters
        // Zero array initially
        int freq[SIZE]{};
        for (auto& c : s){
            freq[c - 'a']++;
        }
        
        for (auto& c : t){
            freq[c - 'a']--;
        }

        for (auto& f : freq) {
            if (f != 0) {
                return false;
            }
        }
        
        return true;
    }
};

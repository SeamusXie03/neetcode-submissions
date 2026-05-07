class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        // Evaluate at compile time
        constexpr int SIZE = 'z' - 'a';

        // Since we are only looking at lowercase English letters
        // Zero array initially
        int s_freq[SIZE]{};
        for (auto& c : s){
            s_freq[c - 'a']++;
        }
        
        int t_freq[SIZE]{};
        for (auto& c : t){
            t_freq[c - 'a']++;
        }

        for (auto idx = 0; idx < SIZE; idx++) {
            if (s_freq[idx] != t_freq[idx]) {
                return false;
            }
        } 

        return true;
    }
};

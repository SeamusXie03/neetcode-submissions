class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        constexpr int SIZE = 'z' - 'a' + 1;

        int freq[SIZE]{};

        for (auto& c : s) {
            freq[c - 'a']++;
        }

        for (auto& c : t) {
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

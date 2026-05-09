class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        vector<int> counts(26, 0);

        for (int idx = 0; idx < s.size(); idx++) {
            counts[s[idx] - 'a']++;
            counts[t[idx] - 'a']--;
        }

        for (int& count : counts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};

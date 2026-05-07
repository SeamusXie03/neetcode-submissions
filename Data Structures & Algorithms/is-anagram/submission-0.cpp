class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> s_count, t_count; 
        for (auto index = 0; index < s.length(); index++) {
            s_count[s[index]]++;
            t_count[t[index]]++;
        }

        return s_count == t_count;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map, t_map;

        if (s.size() != t.size()) {
            return false;
        }

        for (auto index = 0; index < s.size(); index++) {
            s_map[s[index]]++;
            t_map[t[index]]++;
        } 

        return s_map == t_map;
    }
};

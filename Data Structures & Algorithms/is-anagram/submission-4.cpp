class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_count (26, 0);
        vector<int> t_count (26, 0);

        for (auto index = 0; index < s.size(); index++) {
            s_count[s[index] - 'a']++;
        } 

        for (auto index = 0; index < t.size(); index++) {
            t_count[t[index] - 'a']++;
        } 

        return s_count == t_count;
    }
};

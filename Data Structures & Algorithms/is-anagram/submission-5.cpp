class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_count (26, 0);
        vector<int> t_count (26, 0);

        for (auto c : s) {
            s_count[c - 'a']++;
        } 

        for (auto c : t) {
            t_count[c - 'a']++;
        } 

        return s_count == t_count;
    }
};

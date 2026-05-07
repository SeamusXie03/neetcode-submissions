class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strs_map;

        for (auto& str : strs) {
            vector<int> count(26, 0);

            for (auto& c : str) {
                count[c - 'a']++;
            }

            string key = "";
            for (auto val : count) {
                key += to_string(val) + ",";
            }

            strs_map[key].push_back(str);
        } 

        vector<vector<string>> group;
        for (auto& item : strs_map) {
            group.push_back(item.second);
        }

        return group;
    }
};

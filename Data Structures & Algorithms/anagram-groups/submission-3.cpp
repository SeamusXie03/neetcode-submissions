class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keyWord;

        for (auto& str : strs) {
            keyWord[composeId(str)].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& it : keyWord) {
            result.push_back(it.second);
        }

        return result;
    }

    string composeId(string& str) {
        vector<int> charCount(26, 0);

        for (char& c : str) {
            charCount[c - 'a']++;
        }

        string key = "";
        for (int count : charCount) {
            key += to_string(count) + "-";
        }

        return key;
    }
};

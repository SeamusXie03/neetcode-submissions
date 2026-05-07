class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> keyWord;

        for (const string& str : strs) {
            keyWord[composeId(str)].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& it : keyWord) {
            result.push_back(it.second);
        }

        return result;
    }

    string composeId(const string& str) {
        array<int, 26> charCount{};

        for (const char& c : str) {
            charCount[c - 'a']++;
        }

        string key = "";
        for (const int count : charCount) {
            key += to_string(count) + "-";
        }

        return key;
    }
};

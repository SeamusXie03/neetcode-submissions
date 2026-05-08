class Solution {
public:

    string encode(vector<string>& strs) {
        string message = "";

        for (const string& str : strs) {
            message += to_string(str.size()) + "#" + str;
        }

        return message;
    }

    vector<string> decode(string s) {
        vector<string> result;

        string lStr = "";

        for (int idx = 0; idx < s.size(); idx++) {
            if (s[idx] == '#') {
                int length = stoi(lStr);
                lStr = "";
                result.push_back(s.substr(idx + 1, length));
                
                idx += length;
            } else {
                lStr += s[idx];
            }
        }

        return result;
    }
};

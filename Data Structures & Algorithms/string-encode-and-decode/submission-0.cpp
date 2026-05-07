class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (const auto& str : strs) {
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        for (int idx = 0; idx < s.size(); idx++) {
            string size_s = "";
            while (s[idx] != '#') {
                size_s += s[idx];
                idx++;
            }
            int size = stoi(size_s);
            idx++;
            
            string str = "";
            for (int idy = 0; idy < size; idy++) {
                str += s[idx + idy];
            }
            result.push_back(str);

            idx += size - 1;
        }

        return result;
    }
};

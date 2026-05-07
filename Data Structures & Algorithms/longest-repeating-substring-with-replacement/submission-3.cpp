// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         unordered_map<char, int> char_map;
// 
//         int result = 0;
//         int l = 0;
//         int maxf = 0;
// 
//         for (int r = 0; r < s.size(); r++) {
//             char_map[s[r]]++;
//             maxf = max(maxf, char_map[s[r]]);
// 
//             while ((r - l + 1) - maxf > k) {
//                 char_map[s[r]]--;
//                 l++;
//             }
//             result = max(result, r - l + 1);
//         }
//         
//         return result;
//     }
// };
// 

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
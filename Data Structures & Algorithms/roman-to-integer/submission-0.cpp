class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romInt = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int sum = romInt[s[s.size() - 1]];

        for (int idx = 0; idx < s.size() - 1; idx++) {
            int curVal = romInt[s[idx]];
            int nxtVal = romInt[s[idx + 1]];

            if (curVal >= nxtVal) {
                sum += curVal;
            } else {
                sum -= curVal;
            }
        }
        
        return sum;
    }
};
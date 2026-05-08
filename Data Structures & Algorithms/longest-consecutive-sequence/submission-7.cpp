class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // val, length
        unordered_map<int, int> valLength;
        int maxLen = 0;

        for (const int& num : nums) {
            if (valLength[num] != 0) {
                continue;
            }

            int lTerminal = num - valLength[num - 1];
            int rTerminal = num + valLength[num + 1];

            int length = valLength[lTerminal] + valLength[rTerminal] + 1;
            valLength[lTerminal] = length;
            valLength[rTerminal] = length;
            valLength[num] = length;

            maxLen = max(length, maxLen);
        }

        return maxLen;
    }
};

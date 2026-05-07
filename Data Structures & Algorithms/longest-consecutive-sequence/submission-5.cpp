class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> np;

        int res = 0;
        for (const auto& num : nums) {
            // insert placeholder
            if (!np[num]) {
                np[num] = np[num - 1] + np[num + 1] + 1;
                np[num - np[num - 1]] = np[num];
                np[num + np[num + 1]] = np[num];
                res = max(np[num], res);
            }
        }

        return res;
    }
};

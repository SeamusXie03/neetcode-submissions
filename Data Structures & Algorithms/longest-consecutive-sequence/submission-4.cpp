class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // value, count
        unordered_map<int, int> mp;

        int res = 0;
        for (const auto& num : nums) {
            if (mp[num]) {
                continue;
            }

            int length = mp[num - 1] + mp[num + 1] + 1;

            mp[num] = length;
            mp[num - mp[num - 1]] = length;
            mp[num + mp[num + 1]] = length;

            res = max(length, res);
        }

        return res;
    }
};

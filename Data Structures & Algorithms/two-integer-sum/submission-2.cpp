class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value, index
        unordered_map<int, int> val_map;

        for (auto idx = 0; idx < nums.size(); idx++) {
            auto diff = target - nums[idx];

            if (val_map.count(diff)) {
                return {val_map[diff], idx};
            }

            val_map[nums[idx]] = idx;
        }
    }
};

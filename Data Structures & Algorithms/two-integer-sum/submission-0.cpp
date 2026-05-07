class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // num, index
        unordered_map<int, int> num_map;

        for (auto index = 0; index < nums.size(); index++) {
            auto diff = target - nums[index];

            if (num_map.contains(diff)) {
                return {num_map[diff], index};
            } else {
                num_map.insert({nums[index], index});
            }
        }
    }
};

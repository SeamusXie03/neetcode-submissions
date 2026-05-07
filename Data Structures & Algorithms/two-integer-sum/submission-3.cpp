class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value, index
        unordered_map<int, int> nums_dict;

        for (auto i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (nums_dict.contains(diff)) {
                return {nums_dict[diff], i};
            } else {
                nums_dict[nums[i]] = i;
            }
        }
    }
};

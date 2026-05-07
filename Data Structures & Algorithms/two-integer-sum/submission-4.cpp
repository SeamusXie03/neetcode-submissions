class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value, index
        unordered_map<int, int> nums_dict;

        for (auto i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            // Iterator avoids the second hashmap look up
            auto it = nums_dict.find(diff);
            if (it != nums_dict.end()) {
                return {it->second, i};
            } else {
                nums_dict[nums[i]] = i;
            }
        }

        return {};
    }
};

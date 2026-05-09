class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // value -> index
        unordered_map<int, int> valIdx;

        for (int idx = 0; idx < nums.size(); idx++) {
            int diff = target - nums[idx];

            if (valIdx.contains(diff)) {
                return {valIdx[diff], idx};
            }

            if (!valIdx.contains(nums[idx])) {
                valIdx[nums[idx]] = idx;
            }
        }

        return {-1, -1};
    }
};

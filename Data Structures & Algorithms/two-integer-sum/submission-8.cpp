class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numIdx;

        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];

            if (numIdx.contains(diff)) {
                return {numIdx[diff], i};
            }

            numIdx[nums[i]] = i;
        }

        return {-1, -1};
    }
};

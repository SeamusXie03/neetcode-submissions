class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> nums_set = unordered_set<int>(nums.begin(), nums.end());

        return nums_set.size() < nums.size();
    }
};
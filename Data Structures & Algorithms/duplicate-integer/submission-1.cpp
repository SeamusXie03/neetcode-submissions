class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen_num;

        for (const auto &num : nums) {
            if (seen_num.contains(num)) {
                return true;
            }
            seen_num.insert(num);
        }

        return false;
    }
};
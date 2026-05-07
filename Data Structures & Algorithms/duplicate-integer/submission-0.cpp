class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (const auto& val : nums) {
            auto it = seen.find(val);
            if (it != seen.end()) {
                return true;
            } else {
                seen.insert(val);
            }
        }

        return false;
    }
};
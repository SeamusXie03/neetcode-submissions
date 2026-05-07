class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (auto& num : nums) {
            bool exists = (seen.find(num) != seen.end());

            if (exists) {
                return true;
            } else {
                seen.insert(num);
            }
        }
        
        return false;
    }
};
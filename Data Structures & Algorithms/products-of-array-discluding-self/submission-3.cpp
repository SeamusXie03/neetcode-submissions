class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        // compute prefix product
        vector<int> prefix(size, 1);
        for (int i = 1; i < size; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        // compute suffix product
        vector<int> suffix(size, 1);
        for (int i = size - 2; i >= 0 ; i--) {
            suffix[i] = nums[i + 1] * suffix[i + 1];
        }

        vector<int>& result = prefix;
        for (int i = 0; i < size; i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};

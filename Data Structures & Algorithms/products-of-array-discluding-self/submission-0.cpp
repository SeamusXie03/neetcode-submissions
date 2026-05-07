class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> prefix (size);
        vector<int> surfix (size);

        prefix[0] = 1;
        for (auto idx = 1; idx < size; idx++) {
            prefix[idx] = prefix[idx - 1] * nums[idx - 1];
        }

        surfix[size - 1] = 1;
        for (auto idx = size - 2; idx >= 0; idx--) {
            surfix[idx] = surfix[idx + 1] * nums[idx + 1];
        }

        vector<int> result (nums.size());
        for (auto idx = 0; idx < nums.size(); idx++) {
            result[idx] = prefix[idx] * surfix[idx];
        }

        return result;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        // compute exclusive prefix product
        vector<int> result(size, 1);
        for (int i = 1; i < size; i++) {
            result[i] = nums[i - 1] * result[i - 1];
        }

        // complete with suffix product
        int suffix = 1;
        for (int i = size - 1; i >= 0 ; i--) {
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;
    }
};

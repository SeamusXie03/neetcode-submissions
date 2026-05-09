class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(nums.size());

        // compute prefix product
        int runProd = 1;
        for (int idx = 0; idx < n; idx++) {
            result[idx] = runProd;
            runProd *= nums[idx];
        }

        runProd = 1;
        // compute postfix product
        for (int idx = n - 1; idx >= 0; idx--) {
            result[idx] *= runProd;
            runProd *= nums[idx];
        }

        return result;
    }
};

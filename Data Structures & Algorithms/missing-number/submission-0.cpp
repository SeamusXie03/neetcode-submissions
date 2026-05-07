class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ref_sum = 0;
        for (int i = 0; i <= nums.size(); i++) {
            ref_sum += i;
        }

        int sum = 0;
        for (int& num : nums) {
            sum += num;
        }

        return ref_sum - sum;
    }
};

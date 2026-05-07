class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ref_sum = 0;
        for (int i = 0; i <= nums.size(); i++) {
            ref_sum += i;
        }

        for (int& num : nums) {
            ref_sum -= num;
        }

        return ref_sum;
    }
};

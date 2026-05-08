class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {
            int med = l + (r - l) / 2;

            if (nums[med] > nums[r]) {
                l = med + 1;
            } else {
                r = med;
            }
        }

        return nums[l];
    }
};

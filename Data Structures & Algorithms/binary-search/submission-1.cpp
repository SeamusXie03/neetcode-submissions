class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int med = l + (r - l);

            if (nums[med] == target) {
                return med;
            } else if (nums[med] > target) {
                r = med - 1;
            } else {
                l = med + 1;
            }
        }

        return -1;
    }
};

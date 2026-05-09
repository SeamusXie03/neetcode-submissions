class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int med = l + (r - l) / 2;

            if (nums[med] == target) {
                return med;
            } else if (nums[med] < target) {
                l = med + 1;
            } else {
                r = med - 1;
            }
        }
        
        return -1;
    }
};

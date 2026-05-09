class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>()); // o(n logn)

        return nums[k - 1];
    }
};

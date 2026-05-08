class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int idx = 0; idx < nums.size(); idx++) {
            if (idx > 0 && nums[idx] == nums[idx - 1]) {
                continue;
            }

            int lIdx = idx + 1;
            int rIdx = nums.size() - 1;

            while (lIdx < rIdx) {
                int sum = nums[idx] + nums[lIdx] + nums[rIdx];

                if (sum == 0) {
                    result.push_back({nums[idx], nums[lIdx], nums[rIdx]});

                    lIdx++;
                    rIdx--;

                    while (lIdx < rIdx && nums[lIdx] == nums[lIdx - 1]) {
                        lIdx++;
                    }

                    while (lIdx < rIdx && nums[rIdx] == nums[rIdx + 1]) {
                        rIdx--;
                    }
                } else if (sum < 0) {
                    lIdx++;
                } else {
                    rIdx--;
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        // O(n logn)
        sort(nums.begin(), nums.end());

        for (int idx = 0; idx < nums.size(); idx++) {
            // duplicate detection
            if (idx > 0 && (nums[idx - 1] == nums[idx])) {
                continue;
            }

            int lIdx = idx + 1;
            int rIdx = nums.size() - 1;

            while (lIdx < rIdx) {
                int sum = nums[idx] + nums[lIdx] + nums[rIdx];

                if (sum == 0) {
                    result.push_back({nums[idx], nums[lIdx], nums[rIdx]});

                    do {
                        lIdx++;
                    } while (nums[lIdx] == nums[lIdx - 1]);
                    
                    do {
                        rIdx--;
                    } while (nums[rIdx] == nums[rIdx + 1]);
                } else if (sum < 0) {
                    do {
                        lIdx++;
                    } while (nums[lIdx] == nums[lIdx - 1]);
                } else {
                    do {
                        rIdx--;
                    } while (nums[rIdx] == nums[rIdx + 1]);
                }
            } 
        }

        return result;
    }
};

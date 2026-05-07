class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        set<int> num_set (nums.begin(), nums.end());
        vector<int> num_vec (num_set.begin(), num_set.end());

        int result = 1;
        int max = result;

        for (auto idx = 1; idx < num_vec.size(); idx++) {
            if (num_vec[idx] == num_vec[idx - 1] + 1) {
                // consecutive
                result++;
            } else {
                // not consecutive
                if (max < result) {
                    max = result;
                }
                result = 1;
            }
        }
        
        if (max < result) {
            max = result;
        }

        return max;
    }
};

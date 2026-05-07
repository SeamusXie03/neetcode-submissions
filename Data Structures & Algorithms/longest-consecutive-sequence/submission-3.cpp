class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set (nums.begin(), nums.end());

        int count = 1;
        int max = 0;
        for (const auto& num : nums_set) {
            int start = num;
            while (nums_set.contains(++start)) {
                count++;
            } 
            
            if (max < count) {
                max = count;
            }

            count = 1;
        }

        return max;
    }
};

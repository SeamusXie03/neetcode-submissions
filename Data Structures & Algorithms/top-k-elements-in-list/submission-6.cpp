class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // value, count
        unordered_map<int, int> valCount; // O(n)

        // O(n)
        for (int& num : nums) {
            valCount[num]++;
        }

        // Bucket sort
        vector<vector<int>> buckets(nums.size() + 1); // O(n)

        // O(n)
        for (auto& [value, count] : valCount) {
            buckets[count].push_back(value);
        }

        vector<int> result;

        // iterate from the back, since we want the most frequent
        for (int idx = nums.size(); idx >= 0; idx--) {
            for (int& value : buckets[idx]) {
                if (result.size() < k) {
                    result.push_back(value);
                } else {
                    return result;
                }
            }
        }

        return result;
    }
};

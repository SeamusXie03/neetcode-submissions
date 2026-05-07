class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // value -> frequency
        unordered_map<int, int> valCount;

        for (int num : nums) {
            valCount[num]++;
        }

        // Frequency can range from [0, nums.size()]
        // bucket[f] contains all numbers appearing f times
        vector<vector<int>> buckets(nums.size() + 1);

        for (const auto& [val, count] : valCount) {
            buckets[count].push_back(val);
        }

        vector<int> result;

        // Traverse frequencies from high to low
        for (int freq = buckets.size() - 1; freq >= 1; freq--) {

            // Add all values with current frequency
            for (int val : buckets[freq]) {
                result.push_back(val);

                // Stop once we collected k elements
                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // value, count
        unordered_map<int, int> valCount;

        for (const int& num : nums) {
            valCount[num] += 1;
        }

        // one value can appear [0, n] times
        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& it : valCount) {
            buckets[it.second].push_back(it.first);
        } 

        vector<int> result;
        int gap = k;
        int idx = 0;
        int lastIdx = buckets.size() - 1;
        while (gap != 0) {
            vector<int>& bucket = buckets[lastIdx - idx];
            idx++;

            result.insert(result.end(),
                bucket.begin(),
                bucket.end());
            
            gap -= bucket.size();
        }

        return result;
    }
};

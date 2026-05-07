class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // value, count
        unordered_map<int, int> val_count;

        for (auto& num : nums) {
            val_count[num]++;
        }

        vector<pair<int, int>> arr;

        for (const auto& item : val_count) {
            arr.push_back({item.second, item.first});
        }
        sort(arr.rbegin(), arr.rend());
        
        vector<int> result;
        for (auto i = 0; i < k; i++) {
            result.push_back(arr[i].second);
        }

        return result;
    }
};

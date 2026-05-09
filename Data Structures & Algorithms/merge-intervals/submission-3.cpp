class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),
            intervals.end(),
            [](const auto& a, const auto& b) {
                return a[0] < b[0];
            }
        );

        vector<int> curInterval = intervals[0];
        vector<vector<int>> result;

        for (int idx = 1; idx < intervals.size(); idx++) {
            if (curInterval[1] >= intervals[idx][0]) {
                curInterval[1] = max(curInterval[1], intervals[idx][1]);
            } else {
                result.push_back(curInterval);
                curInterval = intervals[idx];
            }
        }

        result.push_back(curInterval);
        return result;
    }
};
